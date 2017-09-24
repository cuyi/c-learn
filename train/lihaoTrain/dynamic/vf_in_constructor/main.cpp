#include <iostream>



class BaseClass
{
public:
    BaseClass()
    {    
        Print();
    }

    virtual void Print()
    {
        std::cout << "BaseClass::Print()" << std::endl;
    }

    virtual ~BaseClass(){};
};


class DerivedClass: public BaseClass
{
public:
    DerivedClass()
    {
        Print();
    }
    
    virtual void Print()
    {
        std::cout << "DerivedClass::Print()" << std::endl;
    }

    virtual ~DerivedClass(){};
};  

 
int main()
{
    BaseClass *pBaseClass = new DerivedClass;
    pBaseClass->Print();
    delete pBaseClass;
}
