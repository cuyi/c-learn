#include <iostream>
#


int main(void)
{
    int a = 100;
    auto f = [a]{return a;};
    a = 0;

    auto r = f;
    std::cout << r() << std::endl;
}
