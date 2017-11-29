#include <iostream>
#include <cstdint>
#include <list>
#include <string>
#include "dllist.hpp"

using namespace std;

uint64_t rdtsc(void)
{
    uint32_t lo, hi;
    /* We cannot use "=A", since this would use %rax on x86_64 */
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return (uint64_t)hi << 32 | lo;
}

class Element{
public:
    Element() = default;
    ~Element() = default;
    bool operator==(const Element& other) const
    {
        return (value == other.value && str == other.str);
    }
private:
    uint32_t value = 9;
    std::string str = "love";
};

int main(void)
{
    LinkedList<Element> llobj;
    Element elobj;
    
    uint64_t start = rdtsc();
    for(int i = 0; i < 10000000; ++i)
    {
        llobj.addToLast(elobj);
    }
    uint64_t end = rdtsc();
    std::cout << "total: " << llobj.elementToatal() << std::endl;
    std::cout << "my add time: " << end - start << std::endl;
    
    std::cout << "-------------------------------\n";
    
    std::list<Element> stdllobj;
    start = rdtsc();
    for(int i = 0 ; i < 10000000; ++i)
    {
        stdllobj.push_back(elobj);
    }
    end = rdtsc();
    std::cout << "total: " << stdllobj.size() << std::endl;
    std::cout << "std push_back time: " << end - start << std::endl;
    
    std::cout << "===============================\n";
    
    start = rdtsc();
    for(int i = 0; i < 10000000; ++i)
    {
        llobj.remove(elobj);
    }
    end = rdtsc();
    std::cout << "total: " << llobj.elementToatal() << std::endl;
    std::cout << "my remove time: " << end - start << std::endl;
    
    std::cout << "-------------------------------\n";
    start = rdtsc();
    for(int i = 0; i < 10000000; ++i)
    {
        stdllobj.remove(elobj);
    }
    end = rdtsc();
    std::cout << "total: " << stdllobj.size() << std::endl;
    std::cout << "std remove time: " << end - start << std::endl;
    
    return 0;
    
}
