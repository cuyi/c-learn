#include <iostream>
#include <cstring>
#include <string>
#include <type_traits>

#define elementsNumOf(array) (sizeof(array) / sizeof(array[0]))


template <typename T>
std::size_t getMaxElementIndexInArray(T arr[], const std::size_t size)
{
    if(arr == nullptr)
    {
        printf("empty arr with address: %x\n", arr);
        return -1;
    }

    if(size == 1)
    {
        return 0;
    }
    
    auto tempVal = arr[0];
    std::size_t ret = 0;
    for(std::size_t idx = 1; idx < size; ++idx)
    {
        
        if(tempVal < arr[idx])
        {
            tempVal = arr[idx];
            ret = idx;
        }
    }

    return ret;
}

template<>
std::size_t getMaxElementIndexInArray(char* arr[], const std::size_t size)
{
    if(arr == nullptr)
    {
        printf("empty arr with address: %x\n", arr);
        return -1;
    }

    
    if(size == 1)
    {
        return 0;
    }

    auto tempVal = arr[0];
    std::size_t ret = 0;
    for(std::size_t idx = 1; idx < size; ++idx)
    {
        if(strcmp(tempVal, arr[idx]) < 0)
        {
            tempVal = arr[idx];
            ret = idx;
        }
    }

    return ret;
}

int main(void)
{
    int arr[10] = {4, 5, 1, 2, 5, 6, 8, 3, 9, 2};
    std::size_t idx = getMaxElementIndexInArray(arr, elementsNumOf(arr));
    std::cout << arr[idx] << std::endl;

    const char *s = "I love you more I CAN saY";
    std::size_t idx1 = getMaxElementIndexInArray(s, elementsNumOf(s));
    std::cout << s[idx1] << std::endl;

    char* p[]{  (char*)"I hate you more I can Say", 
                (char*)"yOU GET the right answer",
                (char*)"what", 
                (char*)"how", 
                (char*)"can't believe this", 
                (char*)"tomorrow",
                (char*)"come on", 
                (char*)"yestarday", 
                (char*)"get up", 
                (char*)"perfect", 
                (char*)"hahahaha"};
    std::size_t idx2 = getMaxElementIndexInArray(p, elementsNumOf(p));
    std::cout << p[idx2] << std::endl;
    
    std::string str[]{  "I hate you more I can Say", 
                        "yOU GET the right answer",
                        "what", 
                        "how", 
                        "can't believe this", 
                        "tomorrow",
                        "come on", 
                        "yestarday", 
                        "get up", 
                        "perfect", 
                        "hahahaha"};
    std::size_t idx3 = getMaxElementIndexInArray(str, elementsNumOf(str));
    std::cout << str[idx3] << std::endl;

    return 0;
}
