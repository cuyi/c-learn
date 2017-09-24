#include <cstdio>
#include <unistd.h> // unistd.h 是 C 和 C++ 程序设计语言中提供对 POSIX 操作系统 API 的访问功能的头文件的名称
#include <sys/times.h>
#include "timeConsumingFun.hpp"

int main(void)
{
    clock_t tBeginTime = times(NULL);
    timeingFunc();
    clock_t tEndTime = times(NULL);

    double milliseconds = (double)(tEndTime - tBeginTime) * 1000 / sysconf(_SC_CLK_TCK);

    printf("[times] Cost Time = %fms\n", milliseconds);

    return 0;
}

