#include <iostream>


int main(void)
{
    std::cout << std::boolalpha     // enable boolalpha flag in the stream
        << true << std::endl;

    std::cout << false << std::endl;


    std::cout << std::noboolalpha   // disable boolalpha flag in the stream
        << true << std::endl;

    std::cout << false << std::endl;

    return 0;
}