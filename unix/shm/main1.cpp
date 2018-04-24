#include    <sys/types.h>  
#include    <sys/ipc.h>  
#include    <sys/shm.h>  
#include    <stdio.h>
#include    <stdlib.h>
#include    <error.h>  
  
#define SHM_SIZE    4096  
#define SHM_MODE    (SHM_R | SHM_W) /* user read/write */  
  
int main(void)  
{  
    int     shmid;  
    char    *shmptr;  
  
    if ( (shmid = shmget(0x44, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0)  
        perror("shmget");  
  
    if ( (shmptr = (char *)shmat(shmid, 0, 0)) == (void *) -1)  
        perror("shmat");  
      
    /* �������ڴ�д���� */  
    sprintf(shmptr, "%s", "hello, world");  
  
    exit(0);  
}
