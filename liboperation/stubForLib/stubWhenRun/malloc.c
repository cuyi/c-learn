#ifdef RUNTIME
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

void *malloc(size_t size)
{
    void *(*mallocp)(size_t size);
    char *error;
    // ���ұ�׼���ʵ��
    mallocp = dlsym(RTLD_NEXT, "malloc");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    void *ptr = mallocp(size);
    printf("[debug] malloc size %d\n", (int)size);
    return ptr;
}

void free(void *ptr)
{
    void (*freep)(void *ptr);
    char *error;
    freep = dlsym(RTLD_NEXT, "free");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    freep(ptr);
    printf("[debug] free %p\n", ptr);
}
#endif