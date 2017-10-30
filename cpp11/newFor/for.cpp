#include <iostream>
#include <array>

int main(void)
{
    std::array<double, 5> dbArr{2.2, 4.5, 4.3, 4.4, 9.8};

    std::cout << "dbArr content:\n";
    for(auto e: dbArr)
        std::cout << e << std::endl;

    std::cout << "modify dbArr content\n";
    for(auto& e: dbArr)
        e += 1.0;

    std::cout << "dbArr content:\n";
    for(auto e: dbArr)
        std::cout << e << std::endl;
    
    return 0;
}
