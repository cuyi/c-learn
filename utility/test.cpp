#include <iostream>
#include "bits.hpp"

int main(void)
{
    int sysbit = getSystemBits();
    int programbit = getProgramBits();
    std::cout << "sysbit = " << sysbit << std::endl;
    std::cout << "programbit = " << programbit << std::endl;

    return 0;
}
