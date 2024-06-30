/*
 * 在子进程中打开一个文件描述符，然后将它传递给父进程，父进程则通过读取该文件描述符来获得文件中的内容
 * 传递fd并不是传递fd的value,而是要在接收进程创建一个新的fd,并且该fd和发送进程被传递的fd是指向内核中的相同的文件表项。
 * 利用unix域socket在进程中的传递特殊的额辅助数据，以实现fd的传递。
 */

#include<sys/socket.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

static const int CONTROL_LEN CMSG_LEN(sizeof(int));

//发送文件描述符，fd参数是用来传递信息的unix域socket,fd_to_send参数是带发送的文件描述符
void send_fd(int fd,int fd_to_send)
{
	struct iovec iov[1];
	struct msghdr msg;
	char buf[0];

	iov[0].iov_base = buf;
	iov[0].iov_len = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	struct cmsghdr cm;
	cm.cmsg_len = CONTROL_LEN;
	cm.cmsg_level = SOL_SOCKET;
	cm.cmsg_type = SCM_RIGHTS;
	*(int *)CMSG_DATA(&cm) = fd_to_send;
	msg.msg_control = &cm;//设置辅助数据。
	msg.msg_controllen = CONTROL_LEN;

	sendmsg(fd,&msg,0);
}


//接收目标文件描述符
int recv_fd(int fd)
{
	struct iovec iov[1];
	struct msghdr msg;
	char buf[0];
	iov[0].iov_base = buf;
	iov[0].iov_len = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	cmsghdr cm;
	msg.msg_control = &cm;
	msg.msg_controllen = CONTROL_LEN;

	recvmsg(fd,&msg,0);
	int fd_to_read = *(int *)CMSG_DATA(&cm);
	return fd_to_read;
}

int main(int argc,char **argc)
{
	int pipefd[2];
	int fd_to_pass = 0;
	//创建父子进程的管道，文件描述符pipefd[0]和pipefd[1]都是unix域socket
	int ret socketpair(PF_UNIX,SOCK_DGRAM,0,pipefd);
	assert(ret!=-1);

	pid_t pid = fork();
	assert(pid>=0);

	if(pid==0){
		close(pipefd[0]);
		fd_to_pass = open("test.txt",O_RDWR,0666);
		//子进程通过管道将文件描述符发送到父进程，如果文件test.txt打开失败，则子进程将输入文件描述符发送到父进程
		send_fd(pipefd[1],(fd_to_pass>0)? fd_to_pass:0);
		exit(0);
	}
	close(pipefd[1]);
	fd_to_pass = recv_fd(pipefd[0]);
	char buf[1024];
	memset(buf,'\0',1024);
	read(fd_to_pass,buf,1024);
	printf("i got fd %d and data %s\n",fd_to_pass,buf);
	close(fd_to_pass);
	return 0;
}
