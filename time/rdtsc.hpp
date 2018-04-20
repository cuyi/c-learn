#ifndef _RDTSC_HPP
#define _RDTSC_HPP

#define RDTSC(low, high)  asm volatile("rdtsc" : "=a" (low), "=d" (high))
#define RDTSC_L(low)      asm volatile("rdtsc" : "=a" (low) : : "edx")
#define RDTSC_LL(val)     asm volatile("rdtsc" : "=A" (val))

void AccessCounter(unsigned *hi, unsigned *lo);


typedef unsigned long long cycle_t;
/* Record the current value of the cycle counter. */
inline cycle_t CurrentCycle(void){
    cycle_t tRdtscRes;
    asm volatile("rdtsc" : "=A" (tRdtscRes));
    return tRdtscRes;
}

inline cycle_t CurrentCycle2(void){
    unsigned hi, lo;  
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));  
    return ((cycle_t)lo) | (((cycle_t)hi)<<32);  
}

#endif

