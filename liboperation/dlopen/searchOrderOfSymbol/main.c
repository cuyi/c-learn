#include <stdio.h>
#include <dlfcn.h>
void callee(void)
{
    printf("callee in %s \n",__FILE__);
}

int main()
{
    void * handle = dlopen("libcaller.so", RTLD_DEEPBIND);
    printf("handle is %x\n",handle);
    void (*callcallee)();
    callcallee=dlsym(handle,"callee"); // 之后将会看到，在caller中执行的callee函数和通过dlsym搜索到的符号不同。
    (*callcallee)();
    return 0;    
}