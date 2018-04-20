***************************************************
#include <dlfcn.h>

RTLD_NOW | RTLD_LOCAL

void *dlopen(const char *filename, int flag);
char *dlerror(void);
void *dlsym(void *handle, const char *symbol);
int   dlclose(void *handle);

Link with -ldl.

如果程序中使用dlopen、dlsym、dlclose、dlerror 显示加
载动态库，需要设置链接选项 -ldl
***************************************************
Usage:
1. g++ -fPIC -shared calculate.cpp -o libcalculate.so 
2. g++ -rdynamic -o testdlopen testdlopen.cpp -ldl
3. ./testdlopen