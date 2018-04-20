#include <iostream>

class BaseClass
{
public:
    virtual void print1(){ std::cout << "BaseClass print1" << std::endl; }     
            void print2(){ std::cout << "BaseClass print2" << std::endl; } 
    virtual ~BaseClass(){};       
};

int main()
{
    BaseClass* pBaseClass = new BaseClass;

    pBaseClass->print1();
    pBaseClass->print2();

    delete pBaseClass;

    return 0;
}   
