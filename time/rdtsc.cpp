#include <cstdio>
#include "rdtsc.hpp"

/* Set *hi and *lo to the high and low order bits of the cycle counter.
 * Implementation requires assembly code to use the rdtsc instruction. */
void AccessCounter(unsigned *hi, unsigned *lo){
    asm volatile("rdtsc; movl %%edx,%0; movl %%eax, %1"
    : "=r" (*hi), "=r" (*lo)
    : /* No input */
    : "%edx", "%eax");
}


