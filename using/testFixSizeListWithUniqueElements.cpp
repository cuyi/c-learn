#include <iostream>
#include <atomic>
#include "fixSizeList.hpp"

int main(void)
{
    FixSizeListWithUniqueElement<int, static_cast<uint32_t>(8)> intList;
    int val;
    val++;
    intList.add(val);

    intList.clear();
    int* p= intList.getElements();
    std::cout << *p << std::endl;
    
    return 0;
}
