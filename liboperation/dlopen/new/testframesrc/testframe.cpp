// ++ -rdynamic testframe.cpp -ldl
#include <iostream>

extern "C" {
    #include <stdio.h>
    #include <stdlib.h>
    #include <dlfcn.h>
    #include <c.h>
}

#define LIB_CACULATE_PATH "../sosrc/libs/a.so"
typedef int (*MY_FUNC)();

int main(void)
{
    void *handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    MY_FUNC my_func = NULL;
    *(void **) (&my_func) = dlsym(handle, "start");

    char *error;
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }
    (*my_func)();

    while(true)
    {
        std::cout << "will never print" << std::endl;
    }

    dlclose(handle);
    return 0;
}