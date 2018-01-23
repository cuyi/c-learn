#include <iostream>
#include "anotherCpp.hpp"

void foo::printMval()
{
    std::cout << __FILE__ << '\t' << __LINE__ << '\t' << mVal_ << std::endl;
}
