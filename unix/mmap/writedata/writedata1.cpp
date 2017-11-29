#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(void)
{
    uint8_t* space = new uint8_t[1024];
    const char* filename = "./test.dat";
    const uint32_t fileLength = 1024;
    int fd = open(filename, O_RDWR | O_CREAT, 0766);
    if(fd == -1)
    {
        printf("open or create file: ( %s ) failed", filename);
    }

    if (MAP_FAILED == mmap(space, fileLength, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED, fd, 0))
    {
        printf("mmap error\n");
        printf("errno = %d is: %s\n", errno, strerror(errno));
    }
    space[0] = 'a';
    //space[1] = 'b';
    //write(fd, "ab", 2);
    /*(if (-1 == munmap(space, fileLength))
    {
        perror("munmap error\n");
        printf("errno = %d is: %s\n", errno, strerror(errno));
    }
   
    close(fd);
     */
    return 0;
}