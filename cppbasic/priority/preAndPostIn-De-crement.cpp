#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int16_t> ivec;
    ivec.push_back(23);

    std::cout << "=====================================" << std::endl;
    std::cout << ivec.at(0) << std::endl;                               // 23

    std::cout << "do post-increment: "          << ivec.at(0)++     << std::endl;    // 23
    std::cout << "after post-increment: "       << ivec.at(0)       << std::endl;   // 24

    std::cout << "do pre-increment: "           << ++ivec.at(0)     << std::endl;    // 25   
    std::cout << "after pre-increment: "        << ivec.at(0)       << std::endl;    // 25
/*
    std::cout << "do preANDpost increment: "      << ++ivec.at(0)++   << std::endl;  // 26
    std::cout << "after preANDpost increment: "   << ivec.at(0)       << std::endl;   // 27
*/

    int a = 4;

    // post-increment is prior than pre-increment, post-increment will return a temporary value which is a lvalue.
    // the operand of a built-in prefix increment operator must be a modifiable (non-const) lvalue of non-boolean arithmetic type.
    
    // std::cout << ++a++ << std::endl; // compile error: lvalue required as increment operand
    std::cout << "=====================================" << std::endl;

    return 0;    
}

