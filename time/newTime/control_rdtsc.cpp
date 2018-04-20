#include <iostream>

#include <signal.h>
#include <pthread.h>
#include <sys/prctl.h>

/* 
    利用汇编指令返回 CPU 的时钟周期计数 
    时钟周期: 也叫振荡周期，定义为时钟频率的倒数，
    是计算中最基本、最小的时间单位。
*/
uint64_t rdtsc(void)
{
    uint32_t lo, hi;
    /* We cannot use "=A", since this would use %rax on x86_64 */
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return (uint64_t)hi << 32 | lo;
}

uint64_t tsc = 0;
void start_sim_rdtsc()
{
    if (tsc == 0)
        tsc = rdtsc();

    /*
        generate a SIGSEGV when the process 
        tries to read the timestamp counter
    */
    if (prctl(PR_SET_TSC, PR_TSC_SIGSEGV) == -1)
        perror("prctl PR_TSC_SIGSEGV");
}

void stop_sim_rdtsc()
{
    /*
        the timestamp counter can be read by the process
    */
    if (prctl(PR_SET_TSC, PR_TSC_ENABLE) == -1)
        perror("prctl PR_TSC_ENABLE");
}

void sigsegv_cb(int sig)
{
    /*
    unsigned long *on_stack;
    on_stack              = ((unsigned long *)&on_stack) + 4;
    struct sigcontext *sc = (struct sigcontext *)&((struct ucontext *)on_stack)->uc_mcontext;
    if (*((uint16_t *)sc->rip) == 0x310f) // rdtsc
    {
        sc->rip += 2;

        tsc = rdtsc_tick(tsc);
        sc->rax &= ~0xffffffffull;
        sc->rdx &= ~0xffffffffull;
        sc->rax |= tsc & 0xffffffffull;
        sc->rdx |= tsc >> 32;
    } 
    else 
    {
        print_trace();
        printf("FATAL signal %s(%d) received, aborting\n", strsignal(sig), sig);
        abort();
    }
    */
    printf("you are not allowed to read tsc\n");
    abort();
}

int main(void)
{
    signal(SIGSEGV, SIG_DFL);
    start_sim_rdtsc();

    uint64_t otherTsc;
    otherTsc = rdtsc();

    return 0;
}


