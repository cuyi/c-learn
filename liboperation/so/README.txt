#include <dlfcn.h>

RTLD_NOW | RTLD_LOCAL

void *dlopen(const char *filename, int flag);
char *dlerror(void);
void *dlsym(void *handle, const char *symbol);
int   dlclose(void *handle);

Link with -ldl.

***************************************************

1.  gcc -fPIC -shared calculate.c -o libcalculate.so 
2.  gcc -rdynamic -o testrdso testrdso.c -ldl