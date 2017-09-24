/*
    protected constructor & destructor 使这个类只能成为基类，
    且该基类的构造只能通过其子类来进行。
*/
#include <iostream>

class A{
protected:
    //A() = default;
    A(int p){ m_a = p; }
    ~A(){}
public:
    static A* createInstance(){ if(pInstance == NULL) pInstance = new A(88); return pInstance;}
    int getVal() const { return m_a; }
private:
    static A *pInstance;
    int m_a;
};

class B: public A{
public:
    /*
        若基类只提供了带参数且有非默认参数的构造函数，
        那么子类必须显式调用基类的构造函数，基类构造
        函数的参数通过子类的构造函数的形参传入
    */
    B(int cc):A(cc), m_val(cc){}   
    ~B(){}
private:
    int m_val;
};


A* A::pInstance = nullptr;
int main(void)
{
    //A a;
    B b(9);
    A*  pToa = B::createInstance();
    std::cout << pToa->getVal();
    
    return 0;
}
