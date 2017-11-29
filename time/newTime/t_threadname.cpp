#include <iostream>
#include <pthread.h>
#include <sys/prctl.h>
#include <unistd.h>

void* tmain(void*arg)  
{  
    char name[32];

    if(prctl(PR_SET_NAME, (unsigned long)"tongy_process") == -1)
        perror("PR_SET_NAME error");
    if(prctl(PR_GET_NAME, (unsigned long)name) == -1)
        perror("PR_GET_NAME error");

    printf("PR name is: %s\n", name);
    while(1)
        sleep(1);
}


int main(void)
{
    pthread_t tid;
    pthread_create(&tid, nullptr, tmain, nullptr);
    pthread_join(tid, nullptr);

    return 0;
}
