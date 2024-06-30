# 共享内存

共享内存是最高效的ipc机制，不涉及进程之间的数据传输行为，这种高效率所带来的问题，我们必须使用其他辅助的手段来同步进程对共享内存的访问，否则就会产生竞态条件。

linux共享内存是api都定义在sys/shm.h头文件中，包括4个系统调用：shmget,shmat,shmdt,shmctl。

## shmget系统调用

显然，shmget是创建一段新的共享内存，或者获取一段已经存在的共享内存；

```c++
    #include<sys/shm.h>
    int shmget(key_t key,size_t size,int shmflg);
```

与semget系统调用一样，key参数是一个键值，用来标志一段全局唯一的共享内存。size参数指定共享内存的大小，单位是字节，如果是创建新的共享内存，则size值必须被指定，如果是获取已经存在的共享内存，则可以把size设置为0.
shmget成功时返回一个正整数的值，它是共享内存的标志符，shmget失败时返回-1，并设置errno.

如果shmget用于创建共享内存，则这段共享内存的所有字节都必须都被初始化为0，与之关联的内核数据结构shmid_ds将被创建并初始化，我们需要正确的设置shmid_ds结构体。

## shmat和shmdt系统调用

共享内存被创建/获取之后，我们不能立即访问它，而是先要将它关联到进程的地址空间中，使用完共享内存之后，我们页需要将它从进程的地址空间分离，这2项任务分别由如下的2个系统调用实现。

```c++
    #include<sys/shm.h>
    void shmat(int shm_id,const void* shm_addr,int shmflg);
    int shmdt(const void* shm_addr);

```

其中shm_id参数是由shmget调用返回的共享内存标识符，shm_addr参数指定将共享内存关联到进程的那块地址空间，最终的效果还是收到shmflg参数的可选标志SHM_RND的影响。
shmat成功时返回共享内存被关联的地址，失败时则返回(void*)-1并设置errno，shmat成功时，将修改内核数据结构shmid_ds的部分字段。

## shmctl系统调用
shmctl系统调用设置共享内存的某些属性，其定义如下：
```c++
    #include<sys/shm.h>
    int shmctl(int shm_id,int command,struct shmid_ds* buf);
```

其中，shm_id时由shmget调用返回的共享内存标识符，command参数指定要执行的命令。
shmctl成功时的返回值取决于command参数，失败时返回-1，并设置errno。

## 共享内存的posix方法

linux提供了另外一种利用mmap在无关进程之间共享内存的方式，这种方式无需任何文件的支持，但是它先要使用如下函数来创建或者打开一个Posix共享内存对象：
```c++ 
    #include<sys/mman.h>
    #include<sys/stat.h>
    #include<fcntl.h>
    int shm_open(const char* name,int oflag,mode_t mode);
```

shm_open的使用方法与open系统调用完全相同，
name参数指定要创建/打开的共享内存对象，从可移植的角度考虑，该参数应该使用“/somename”的格式，长度不应该超过NAME_MAX(通常时255)
oflag参数指定创建方式。
shm_open调用成功时，返回一个fd,该fd可以用于后续的mmap调用，从而将共享内存关联到调用进程，shm_open失败时返回-1，并设置errno.

和这个打开的文件最后需要关闭一样，由shm_open创建的共享内存对象使用完毕之后也同样需要删除。
```c++
    #include<sys/mman.h>
    #include<sys/stat.h>
    #include<fcntl.h>
    int shm_unlink(const char* name);
```

该函数将name参数指定的共享内存对象标记为等待删除，当所有使用该共享内存对象的进程都使用了ummap将它从进程中分离之后，系统将销毁这个共享内存对象所占用的资源。

如果在linux平台上使用Posix共享内存函数，则需要在编译的指定链接选项 -lrt option。