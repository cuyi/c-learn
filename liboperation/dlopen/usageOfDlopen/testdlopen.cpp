#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <functional>

extern "C" {
#include "testFunFile.h"
}

extern std::function<decltype(foo)> foo_func;
/*
std::function<decltype(foo)>::result_type foo()
{
	;
}
*/
std::function<void()> foo_func = []() { printf("expected foo() called\n"); };

/*
void foo()
{
	printf("another foo() called\n");	
}
*/


//��̬���ӿ�·��
#define LIB_CACULATE_PATH "./libcalculate.so"

//����ָ��
typedef int (*CAC_FUNC)(int, int);

int main()
{
    void *handle;
    char *error;
    CAC_FUNC cac_func = NULL;

    //�򿪶�̬���ӿ�
    handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    //���֮ǰ���ڵĴ���
    dlerror();

    //��ȡһ������
    *(void **) (&cac_func) = dlsym(handle, "add");
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    printf("add: 2+7 = %d\n", (*cac_func)(2,7));

    cac_func = (CAC_FUNC)dlsym(handle, "sub");
    printf("sub: 9-2 = %d\n", cac_func(9,2));

    cac_func = (CAC_FUNC)dlsym(handle, "mul");
    printf("mul: 3*2 = %d\n", cac_func(3,2));

    cac_func = (CAC_FUNC)dlsym(handle, "div");
    printf("div: 8/2 = %d\n", cac_func(8,2));

    //�رն�̬���ӿ�
    dlclose(handle);
    exit(EXIT_SUCCESS);
}