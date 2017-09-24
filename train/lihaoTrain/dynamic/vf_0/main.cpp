#include <iostream>




class BaseClass
{
public:
    virtual void print1(){ std::cout << "BaseClass print1" << std::endl; } 
    virtual void print2(){ std::cout << "BaseClass print2" << std::endl; } 
    virtual void print3(){ std::cout << "BaseClass print3" << std::endl; }   
            void print4(){ std::cout << "BaseClass print4" << std::endl; } 
    virtual ~BaseClass(){};       
};




int main()
{
    BaseClass* pBaseClass = new BaseClass;

    pBaseClass->print1();
    pBaseClass->print2();
    pBaseClass->print3();
    pBaseClass->print4();

    delete pBaseClass;


#if 1
    BaseClass  b1;
    BaseClass  b2;
	std::cout << sizeof(b1) << std::endl;
    
    std::cout << "&b1= " << std::hex << (long)&b1 << std::endl;
    std::cout << "&b2= " << std::hex << (long)&b2 << std::endl;

    std::cout << "b1's virtual function table address = " << std::hex << *(long*)&b1 << std::endl;
    std::cout << "b2's virtual function table address = " << std::hex << *(long*)&b2 << std::endl;        
            
#endif
    return 0;
}   
