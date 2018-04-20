#include <iostream>

class A{
public:
    A() = default;
    void fun(){std::cout <<" fun \n";}

    void fun2(){std::cout << a << std::endl; }

private:
    int a = 0;
};

int main(void)
{
    A* pA = NULL;
    pA->fun();

    // pA->fun2();

    int val = 5;
    pA = reinterpret_cast <A*>(&val);
    pA->fun();
    
    return 0;
}
