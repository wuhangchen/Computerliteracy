/*
    聊天室程序，修改为一个多进程的服务器，一个子进程处理一个客户连接
    我们所有的客户的socket连接的读缓冲区设置为一块共享内存
*/

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sts/stat.h>
#include<fcntl.h>

#define USER_LIMIT 5
#define BUFFER_SEZE 1024
#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define PROCESS_LIMIT 65536


//封装一个客户必要的连接
struct client_data{
    sockaddr_in address;                //客户端的socket地址
    int connfd;                         //socket文件描述符
    pid_t pid;                          //处理这个连接的子进程的pid
    int pipefd[2];                      //和父进程通信用的管道
};

static const char* shm_name = "/my_shm";
int sig_pipefd[2];
int epollfd;
int listenfd;
int shmfd;
char* share_mem = 0;
client_data* users = 0;                 //客户连接数组，进程使用客户连接的编号来索引数组，即可以取得相关客户连接的数据
int* sub_process = 0;
int user_count = 0 ;
bool stop_child = false;

//将fd设置为非阻塞的
//TODO: 返回old_opiton的意图为何？
int setnonblocking(int fd)
{
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option |　O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

void addfd(int epollfd,int fd)
{
    epoll_event event ;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
}

void sig_handler(int sig)
{
    int save_errno = errno;
    int msg = sig;
    send(sig_pipe[1],(char*)&msg,1,0);
    errno = save_errno;
}

void addsig(int sig,void (*handler)(int),bool restart = true)
{
    struct  sigaction sa;
    memset(&sa,'\0',sizeof(sa));
    sa.sa_handler = handler;
    if(restart)
    {
        sa.sa_flags |= SA_RESETART;
    }
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig,&sa,NULL)!=-1);
    
}

void del_resource()
{
    close(sig_pipefd[0]);
    close(sig_pipefd[1]);
    close(listenfd);
    close(epollfd);
    shm_unlink(shm_name);
    delete []user;
    delete []sub_process;
}

//停止一个子进程
void child_term_handler(int sig)
{
    stop_child = true;
}

//子进程运行函数，参数idx指出了该子进程处理的客户连接的编号，users是保存所有客户连接数据的数组，参数share_mem指出共享内存的起始地址
int run_child(int idx,client_data* users,char* share_mem)
{
    epoll_event events[MAX_EVENT_NUMBER];
    //子进程利用io多路复用技术来同时监听2个fd,客户连接的socket，与父进程通信的管道fd
    int child_epollfd = epoll_create(5);
    assert(child_epollfd != -1);

    int connfd = users[idx].connfd;
    addfd(child_epollfd,connfd);
    int pipefd = users[idx].pipefd[1];
    addfd(child_epollfd,pipefd);
    int ret;
    //子进程需要设置自己的信号处理函数。
    addsig(SIGTERM,child_term_handler,false);

    while(!stop_child)
    {
        int number = epoll_wait(child_epollfd,events,MAX_EVENT_NUMBER,-1);
        if((number<0)&&(errno!=EINTER))
        {
            printf("epoll failure\n");
            break;
        }
        for(int i = 0;i<number;++i)
        {
            int socketfd = events[i].data.fd;

            if((socketfd==connfd) && (events[i].events & EPOLLIN))
            {
                memeset(share_mem+idx*BUFFER_SEZE,'\0',BUFFER_SEZE);
                ret = recv(connfd,share_mem+idx*BUFFER_SEZE,BUFFER_SEZE-1,0);
                if(ret<0)
                {
                    if(errno != EAGAIN)
                    {
                        stop_child = true;
                    }
                }
                else if (ret == 0)
                {
                    stop_child = true;
                }
                else
                {
                    //成功读取客户数据就通知主进程(通过管道)来处理
                    send(pipefd,(char*)&idx,sizeof(idx),0);
                }
                
            }
            else if ((socketfd == pipefd)&&(events[i].events & EPOLLIN))
            {
                int client = 0;
                //接受父进程发送来的数据，既有客户数据到达的连接的编号
                ret = recv(socketfd,(char*)&client,sizeof(client),0)
                if(ret<0)
                {
                    if(errno!=EAGAIN)
                    {
                        stop_child = true;
                    }
                }
                else if (ret == 0)
                {
                    stop_child = true;
                }
                else 
                {
                    send(conndf,share_mem+client*BUFFER_SEZE,BUFFER_SEZE,0);
                }
            }
            else
            {
                continue;
            }

            
            
        }
    }
    close(connfd);
    close(pipefd);
    close(child_epollfd);
    return 0;
}


int main(int argc,char *argv[])
{
    if(argc<=2)
    {
        printf("usage:%s ip_address port_number\n",basename(argv[0]));
        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address,sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);
    address.sin_port=htons(port);

    listenfd = socket(PF_INET,SOCK_STREAM,0);
    assert(listenfd >= 0);

    ret = bind(listenfd,(struct sockaddr*)&address,sizeof(address));
    assert(ret != -1);

    ret = listen(listenfd,5);
    assert(ret != -1);

    user_count = 0;
    users = new client_data[USER_LIMIT+1];
    sub_process new int[PROCESS_LIMIT];
    for(int i=0;i<PROCESS_LIMIT;++i)
    {
        sub_process[i]=-1;
    }
    epoll_event events[MAX_EVENT_NUMBER];
    epollfd = epoll_create(5);
    assert(epollfd!=-1);

    addfd(epollfd,listenfd);
    ret = sockpair(PF_UNIX,SOCK_STREAM,0,sig_pipefd);
    assert(ret != -1);
    setnonblocking(sig_pipefd[1]);
    addfd(epollfd,sig_pipefd[0]);

    addsig(SIGCHLD,sig_handler);
    addsig(SIGTERM,sig_handler);
    addsig(SIGINT,sig_handler);
    addsig(SIGPIPE,SIG_IGN);

    bool stop_server = false;
    bool terminate = false;

    //创建共享内存，作为所有客户socket连接的读缓存
   //TODO:共享内存的设置问题，先调用shm_open 然后还要调用mmap()调用呢？

    shmfd = shm_open(shm_name,_O_CREAT | O_RDWR,0666);
    assert(shmfd != -1);
    ret = ftruncate(shmfd,USER_LIMIT*BUFFER_SEZE);
    assert(ret != -1);

    share_mem = (char*)mmap(NULL,USER_LIMIT*BUFFER_SEZE,PROT_READ | PROT_WARITE,MAP_SHARED,shmfd,0);
    assert(share_mem != MAP_FAILED);

    close(shmfd);

    while(!stop_server)
    {
        int number = epoll_wait(epollfd,events,MAX_EVENT_NUMBER);
        if((number<0)&&(errno != EINTR))
        {
                printf("epoll failures");
                break;
        }
        for(int i=0;i<number;++i)
        {
            int sockfd = events[i].data.fd;
            
            //新的客户连接到来
            if(sockfd == listenfd)
            {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(listenfd,(struct sockaddr*)&client_address,&client_addrlength);

                if(connfd < 0)
                {
                    printf("errno is :%d\n",errno);
                    continue;
                }
                if(user_count>=USER_LIMIT)
                {
                    const char* info = "too many users\n";
                    printf("%s",info);
                    send(connfd,info,strlen(info),0);
                    close(connfd);
                    conintue;
                }
                //保存第user_count个客户端连接的相关数据
                users[user_count].address = client_address;
                users[user_count].connfd = connfd;

                //在主进程和子进程之间建立管道，用来传输必要的数据
                ret = socketpair(PF_UNIX,SOCK_STREAM,0,users[user_count].pipefd);
                assert(ret != -1);

                pid_t pid = fork();
                if(pid<0)
                {
                    close(connfd);
                    continue;
                }
                else if(pid == 0)
                {
                    close(epollfd);
                    close(listenfd);
                    close(users[user_count].pipefd[0]);
                    close(sig_pipefd[0]);
                    close(sig_pipefd[1]);
                    run_child(user_count,users,share_mem);
                    munmap((void*)share_mem,USER_LIMIT*BUFFER_SEZE);
                    exit(0);
                }
                else
                {
                    close(connfd);
                    close(users[user_count].pipe[1]);
                    addfd(epollfd,users[user_count].pipefd[0]);
                    users[user_count].pid = pid;
                    sub_process[pid] = user_count;
                    user_count++;
                }
            }
            //处理信号事件
            else if((sockfd == sig_pipefd[0])&&(events[i].events & EPOLLIN))
            {
                int sig;
                char signal[1024];
                ret = recv(sig_pipefd[0],signals,sizeof(signals),0);
                if(ret == -1)
                {
                    continue;
                }
                else if(ret == 0)
                {
                    continue;
                }
                else
                {
                    for(int i = 0;i<ret;++i)
                    {
                        switch(signals[i])
                        {
                            case SIGCHLD:
                            {
                                pid_d pid;
                                int stat ;
                                while((pid == waitpid(-1,&stat,WNOHAND)) > 0)
                                {
                                    //用子进程的pid取的被关闭的客户连接的编号
                                    int del_user = sub_process[pid];
                                    sub_process[pid] = -1;
                                    if((del_user<0) || (del_user>USER_LIMIT))
                                    {
                                        continue;
                                    }
                                    //清除第del_user个客户连接使用的相关数据
                                    epoll_ctl(epollfd,EPOLL_CTL_DEL,users[del_user].pipefd[0]);
                                    close(users[del_user].pipefd[0]);
                                    users[del_user] = users[--user_count];
                                    sub_process[users[users[del_user].pid]]= del_user;
                                }
                                if(terminate && user_count == 0)
                                {
                                    stop_server = true;
                                }
                                break;
                                
                            }
                            case SIGTERM:
                            case SIGINT:
                            {
                                //结束服务器程序
                                printf("kill all child now\n");
                                if(user_count == 0)
                                {
                                    stop_server = true;
                                    break;
                                }
                                for(int i = 0;i<user_count;++i)
                                {
                                    int pid = users[i].pid;
                                    kill(pid,SIGTERM);
                                }
                                terminate = true;
                                break;
                            }
                            default :
                            {
                                break;
                            }
                        }
                    }
                }
            }

            //某个孩子进程向父进程写入数据。
            else if(events[i].events & EPOLLIN)
            {
                int child = 0;
                //读取管道数据，child变量记录哪个客户连接有数据到达
                ret = recv(sockfd,(char*)&child,sizeof(child),0);
                printf("read data from child accross pipe\n");
                if(ret == -1)
                {
                    continue;
                }
                else if(ret == 0)
                {
                    continue;
                }
                else 
                {
                    //向处负责第child个客户连接的子进程之外的其他子进程发送消息，通知他们有客户数据要写
                    for(int j = 0;j<user_count;++j)
                    {
                        if(users[j].pipefd[0] != sockfd)
                        {
                            printf("send data to child accross pipe\n);
                            send(users[j].pipefd[0],(char*)&child,sizeof(child),0);

                        }
                    }
                }
            }

        }
    }

    del_source();
    return 0;


}