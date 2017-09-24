#include <iostream>

class A{
public:
    A(){ printHello();}
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
    A().printHello();       // Hello in A * 2
    A().callDoSomething();  // Hello in A  A doSomething
 
    A* pAobj = new B;       // Hello in A   Here no override happens, because when construct B it will construct A first.
    pAobj->printHello();    // Hello in B   override correctly
    pAobj->callDoSomething();   // B doSometing
    return 0;
}

