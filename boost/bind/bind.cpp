#include <iostream>
#include <boost/bind.hpp>

void fun(int x, int y)
{
    std::cout << x << ", " << y << std::endl;
}

int main(void)
{
    boost::bind(&fun, 3, 4)();
    boost::bind(&fun, 3, _1)(5);
    boost::bind(&fun, _2, _1)(6,7);
    return 0;
}
