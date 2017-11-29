#include <iostream>
#include <atomic>
#include "fixSizeList.hpp"

/*
    using ns_name::name;
    
    using-declaration: makes the symbol name from the 
    namespace ns_name accessible for unqualified lookup 
    as if declared in the same class scope, block scope, 
    or namespace as where this using-declaration appears.
*/

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
