#include<stdio.h>
#include"malloc.h"

int main(void)
{
    int *p = malloc(sizeof(int));
    *p = 12;
    printf("*p = %d\n", *p);
    //printf("p = %p\n", p);
    free(p);
    return 0;
}