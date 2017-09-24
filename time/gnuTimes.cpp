#include <cstdio>
#include <unistd.h> // unistd.h �� C �� C++ ��������������ṩ�� POSIX ����ϵͳ API �ķ��ʹ��ܵ�ͷ�ļ�������
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

