#include <iostream>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

int main(void)
{
    struct timeval tv1;
    gettimeofday(&tv1, NULL);
    printf("start time:s(%ld), us(%ld)\n", tv1.tv_sec, tv1.tv_usec);
    
    usleep(10000); // sleep 1000 us
    
    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    printf("  end time:s(%ld), us(%ld)\n", tv2.tv_sec, tv2.tv_usec);
    


    return 0;
}
