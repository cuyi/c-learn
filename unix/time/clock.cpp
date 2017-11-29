#include <iostream>
#include <ctime>

#include <unistd.h> // C 和 C++ 中提供对 POSIX 操作系统 API 的访问功能的头文件的名称

int main(void)
{
    int temp{0};

    clock_t start(0), end(0);
    for(int i = 0; i < 10000000; ++i)
        temp++;
    start = clock();
    //sleep(4);
    for(int i = 0; i < 10000000; ++i)
        temp++;
    sleep(1);
    end = clock();
    
    std::cout << start << std::endl;
    std::cout << end   << std::endl;

    
    std::cout << (double)(end - start) /  CLOCKS_PER_SEC << std::endl;
}

