#include <iostream>

class Base{
public:
    Base(){ std::cout << "Base constructor called\n"; }
    virtual ~Base() { std::cout << "Base destructor called\n"; }
};

class Derived: public Base{
public:
    Derived() { std::cout << "Derived constructor called  ( no arg )\n"; }
    Derived(int inVal):val(inVal) { std::cout << "Derived constructor called\n"; }
    ~Derived() { std::cout<< "Derived destructor called\n"; }
private:
    int val = 0;
};


void fun1()
{
    Derived drObj;
}

void fun2()
{
    Derived drObj(44);
}

Derived* fun3()
{
    Derived* pDerived = new Derived();
    return pDerived;
}

Base* fun4()
{
    Base* pBase = new Derived();
    return pBase;
}


int main(void)
{
    fun1();
    std::cout << "----------\n";
    fun2();
    std::cout << "----------\n";
    Derived* p = fun3();
    delete p;
    std::cout << "----------\n";
    Base* pp = fun4();
    delete pp;

    return 0;
}
