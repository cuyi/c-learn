#include <iostream>



class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "BaseClass::BaseClass()" << std::endl;
    }

    virtual void Print()
    {
        std::cout << "BaseClass::Print()" << std::endl;
    }

    //virtual ~BaseClass()
    ~BaseClass()
    {
        std::cout << "BaseClass::~BaseClass()" << std::endl; 
    };
};


class DerivedClass: public BaseClass
{
public:
    DerivedClass()
    {
        std::cout << "DerivedClass::DerivedClass()" << std::endl;
    }
    
    virtual void Print()
    {
        std::cout << "DerivedClass::Print()" << std::endl;
    }

    virtual ~DerivedClass()
    {
        std::cout << "DerivedClass::~DerivedClass()" << std::endl; 
    };
};  

 
int main()
{
    BaseClass *pBaseClass = new DerivedClass;
    delete pBaseClass;
}
