#include <iostream>


typedef void(*Fun)(void);

class BaseClass
{
public:
    virtual void print1(){ std::cout << "BaseClass print1" << std::endl; }
    virtual void print2(){ std::cout << "BaseClass print2" << std::endl; }
    virtual void print3(){ std::cout << "BaseClass print3" << std::endl; }

    virtual ~BaseClass() {}
    void callFirstVirtualFunction()
    {     
        Fun pFun = (Fun)*((long*)(*(long*)this) + 0);
        pFun();
    }

    void callSecondVirtualFunction()
    {     
        Fun pFun = (Fun)*((long*)(*(long*)this) + 1);
        pFun();
    }

    void callThirdVirtualFunction()
    {     
        Fun pFun = (Fun)*((long*)(*(long*)this) + 2);
        pFun();
    }
};

class DerivedClass: public BaseClass
{
public:
    virtual void print1() final{ std::cout << "DerivedClass print1" << std::endl; }
    virtual void print2() final{ std::cout << "DerivedClass print2" << std::endl; }
    //virtual void print3() final{ std::cout << "DerivedClass print3" << std::endl; }
};


int main()
{

#if 0
    BaseClass b1;
    DerivedClass d1;

    b1.callFirstVirtualFunction();
    b1.callSecondVirtualFunction();
    b1.callThirdVirtualFunction();

    d1.callFirstVirtualFunction();
    d1.callSecondVirtualFunction();
    d1.callThirdVirtualFunction();
#endif
    BaseClass *pBase = new BaseClass();
    pBase->callFirstVirtualFunction();
    pBase->callSecondVirtualFunction();
    pBase->callThirdVirtualFunction();
    delete pBase;
    
    pBase = new DerivedClass();
    pBase->callFirstVirtualFunction();
    pBase->callSecondVirtualFunction();
    pBase->callThirdVirtualFunction();
    delete pBase;
 
}
