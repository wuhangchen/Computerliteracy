
/*
 * 实际上，get_memory并不能做任何事情，由于从get_memory中返回时不能获得堆中的内存的地址，那块堆内存也就不能继续引用，
 * 也就得不到释放，因此调用一次就会发生num byte的内存泄漏。
 */
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void get_memory(char *p, int num){
    p = (char*)malloc(sizeof(char)*num);
    return;
}

void test() {
    char *str = nullptr;
    get_memory(str, 10);
    strcpy(str, "hello");
}

int main()
{
    test();
    return 0;
}	


