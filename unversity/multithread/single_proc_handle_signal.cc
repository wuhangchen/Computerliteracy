//使用一个线程来统一处理所有的信号。
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

#define handle_error_en(en,msg)                              \
    do                                                       \
    {                                                        \
        errno = en ;                                         \
        perror(msg);                                         \
        exit(EXIT_FAILURE);                                  \
    }while(0)                                                 