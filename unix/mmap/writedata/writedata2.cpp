#include <stdio.h>
#include <sys/mman.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static int operator-(struct timeval& lsh, struct timeval& rsh)
{
    if (lsh.tv_sec==rsh.tv_sec)
    {
        return lsh.tv_usec - rsh.tv_usec;
    }
    else
    {
        return (lsh.tv_sec-rsh.tv_sec)*1000000 + (lsh.tv_usec - rsh.tv_usec);
    }
}

void test()
{
    struct timeval start;
    struct timeval end;
    const int DATA_LEN = 1024*1024*200;
    char* pData = new char[DATA_LEN]; //200MB
    
    memset(pData, 'a', DATA_LEN);
    
    gettimeofday(&start, NULL);
    
    int fd = open("mmap.dat", O_RDWR | O_CREAT, 0666 );
    if (fd<0)
    {
        printf("open error!\n");
        return;
    }
    
    lseek(fd, DATA_LEN-1, SEEK_SET);
    write(fd, "", 1);
    
    char* p = new char[DATA_LEN];
    //char* p = (char* )mmap(NULL, DATA_LEN, PROT_WRITE, MAP_SHARED, fd, 0);
    printf("lllllllllllllllllll   %p\n", p);
    
    char *px = NULL;
    if (MAP_FAILED == (px = (char*)mmap((void *)p, DATA_LEN, PROT_WRITE, MAP_SHARED, fd, 0)))
    {
        perror("mmap");
        return;
    }
    printf("SSSSSSSSSSSSSSSSSSS   %p\n", px);
    close(fd);
    fd = -1;

    //memcpy(p, pData, DATA_LEN);
    px[0] = pData[0];

    if (-1 == munmap(px, DATA_LEN))
    {
        perror("munmap");
    }
    p = NULL;
    //
    gettimeofday(&end, NULL);
    delete[] pData;
    pData = NULL;
    //显示占用时间
    struct tm stTime;
    localtime_r(&start.tv_sec, &stTime);
    char strTemp[40];
    strftime(strTemp, sizeof(strTemp)-1, "%Y-%m-%d %H:%M:%S", &stTime);
    printf("start=%s.d\n", strTemp, start.tv_usec);
    //
    localtime_r(&end.tv_sec, &stTime);
    strftime(strTemp, sizeof(strTemp)-1, "%Y-%m-%d %H:%M:%S", &stTime);
    printf("end =%s.d\n", strTemp, end.tv_usec);
    printf("spend=%d (%9.3fs)\n", end-start, (double)(end-start)/1000000.0f);
}

int main()
{
    printf("PAGE SIZE = 0x%x, %d\n", sysconf(_SC_PAGE_SIZE), sysconf(_SC_PAGE_SIZE));
    test();
    return 1;
}