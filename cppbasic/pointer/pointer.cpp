#include <stdio.h>
int main(void)
{
    int *p;
    int a=2;
    unsigned long b=1245048;
    p=&a;
    printf("%d\n",*p);
    printf("%p\n",&a);
    printf("%ld\n",&a);

    printf("%d\n",(void*)b);
    
    /*
    //printf("%d\n",*(void*)b);  // 被注释的一行，运行此行会提示错误。
    printf("%d\n",*(int*)b);
    printf("%d\n",*(void**)b);
    */
    return 0;
} 
