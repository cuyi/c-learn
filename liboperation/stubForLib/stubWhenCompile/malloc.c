#ifdef COMPILELINK
#include<stdio.h>
#include<malloc.h>

void *mymalloc(size_t size)
{
    void *ptr = malloc(size);
    printf("[debug] malloc size %d\n", (int)size);
    return ptr;
}

void myfree(void *ptr)
{
    free(ptr);
    printf("[debug] free %p\n", ptr);
}
#endif