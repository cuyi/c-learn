#ifdef LINKTIME
#include<stdio.h>
#include<malloc.h>
//std malloc
//试了直接调用malloc，编译链接ok，但是运行时core
void *__real_malloc(size_t size);
void __real_free(void *ptr);
void *__wrap_malloc(size_t size)
{
    void *ptr = __real_malloc(size);
    printf("[debug] malloc size %d\n", (int)size);
    return ptr;
}
void __wrap_free(void *ptr)
{
    __real_free(ptr);
    printf("[debug] free %p\n", ptr);
}
#endif