#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PATH 1024

int main(int argc, char* argv[])
{
    pid_t pid = getpid();
    
    char pathBuf[MAX_PATH];
    if( readlink("/proc/self/exe", pathBuf, MAX_PATH) <= 0 )
        exit(1);
    
    char* processName = strrchr(pathBuf, '/');
    
    if(processName)
    {
        printf("当前进程ID：%d\n", pid);  
        printf("当前进程名：%s\n", ++processName);  
        printf("当前进程路径：%s\n", pathBuf); 
    }
    
    return 0;
}