#pragma once
#include <iostream>
#include <cstdint>
#include "commonHeader.hpp"

class foo{
public:
    foo() = default;
    void useExternVal()
    {
        val1++; std::cout << "anotherCpp.hpp: val = " << val1 << std::endl;
    }
    void printMval();
private:
    uint32_t mVal_{99};
};