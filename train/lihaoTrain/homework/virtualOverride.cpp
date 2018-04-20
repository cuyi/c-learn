#include <iostream>

class A{
public:
    A() = default;
    virtual void printHello(){ std::cout << "Hello in A\n"; }
    void callDoSomething() { this->doSomething(); }
private:
    virtual void doSomething(){ std::cout << "A doSomething\n"; }
};

class B:public A{
public:
    B() = default;
    void printHello() override { std::cout << "Hello in B\n"; }

    void doSomething() override { std::cout << "B doSomething\n"; }
};


int main(void)
{   
    A().printHello();
    A().callDoSomething();
 
    A* pAobj = new B;
    pAobj->printHello();
    pAobj->callDoSomething();
    return 0;
}

