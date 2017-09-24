#include <stdio.h>
#include <unistd.h>     // alarm, pause , sleep()'s implementation is based on alarm and pause
#include <sys/types.h>
#include <signal.h>     // signal, kill
#include "rdtsc.h"


cycle_t tStart = 0, tEnd = 0;
void TimingHandler(int signo){
    tEnd = CurrentCycle();
    printf("CPU Frequency: %dMHz\n", (tEnd - tStart) / 1000000);
    kill(getpid(), SIGINT);
}

void calcCpuFreq(void){
    signal(SIGALRM, TimingHandler);
    tStart = CurrentCycle();
    alarm(1);
    while(1)
        pause();
}

/* 这程序有问题，有时候会输出负数 
	CPU Frequency:  -140464408MHz	// error
	CPU Frequency:        2497MHz	// ok
	*/
unsigned gCpuFreqInHz = 0;
void calcCpuFreq2(void){
	cycle_t tStart = 0;
	cycle_t tEnd = 0;
    tStart = CurrentCycle();
    sleep(1); // 调用sleep时，进程挂起直到 1s 睡眠时间到达，这期间经过的周期是被其他进程执行的
    tEnd = CurrentCycle();
    gCpuFreqInHz = tStart - tEnd;
    printf("CPU Frequency: %11dMHz\n", (tEnd - tStart) / 1000000);
}

int main(void)
{
    //calcCpuFreq();
    calcCpuFreq2();

    return 0;    
}

