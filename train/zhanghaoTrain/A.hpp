#include <iostream>

class A{
public:
    void fun()
        {
        a = 0;
        b = 0;
        b = 0;
    }
public:
    int a;
protected:
    int b;
private:
    int c;
};

class B:public A{
public:
    void fun_a()
        {
        a = 0;
    }
    void fun_b()
        {
        b = 0;
    }
    // can not use c because of private c
};

