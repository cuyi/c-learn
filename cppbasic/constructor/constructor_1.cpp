// constructor]$ g++ -std=c++11 -O0 -fno-elide-constructors constructor_1.cpp
#include <iostream>

using namespace std;

#define debugFlag 1
struct C {
    C() {}
    C(const C&) { std::cout << "A copy was made.\n"; }
    C& operator=(const C& rhs)
    {
        if(this != &rhs)
        {
            *this = rhs;
        }
        std::cout << "copy assignment is called\n";
        return *this;
    }
#ifdef debugFlag
    C(C&&)
    {
        std::cout << "move constructors called\n";
    }
#endif
};

C f() {
    C o;
    std::cout << "~~~~~~\n";
    return o;
}

void fun(const C objC)
{
    std::cout << "do nothing" << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
    C obj = f();

    std::cout << "Hello Apple!\n";
    f();
    
    std::cout << "Hello Nokia!\n";
    C obj1(obj);

    fun(obj1);

    fun(std::move(obj1));
    return 0;
}
