#include <cmath>
#define TIME_LOOP_NUM 1000000 * 20

void timeingFunc(void)
{
    unsigned int i = 0;
    double y = 0.0;
    for(; i < TIME_LOOP_NUM; ++i)
        y = sin((double)i);
}

