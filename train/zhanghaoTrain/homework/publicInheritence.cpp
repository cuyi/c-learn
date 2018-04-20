#include <iostream>

class Base{
public:
    Base(int val_pub, int val_pro, int val_pri):
        valPub(val_pub),
        valPro(val_pro),
        valPri(val_pri)
    {

    }
    virtual ~Base(){}

public:
    int valPub = 0;
protected:
    int valPro = 0;
private:
    int valPri = 0;
};

class ProtectedDerived: protected Base{
public:
    ProtectedDerived(int val_pub, int val_pro, int val_pri):
        Base(val_pub, 
            val_pro,
            val_pri)
    {

    }
    ~ProtectedDerived(){}

    int proGetBasePub() { return valPub; }
    int proGetBasePro() { return valPro; }
    // int proGetBasePri() { return valPri; }   // cat not get base's privte member whenever what inheritence is used
};

class PublicDerived: public Base{
public:
    PublicDerived(int val_pub, int val_pro, int val_pri):
        Base(val_pub, 
            val_pro,
            val_pri)
    {

    }
    ~PublicDerived(){}

    int pubGetBasePub() { return valPub; }
    int pubGetBasePro() { return valPro; }
    // int pubGetBasePri() { return valPri; }   // cat not get base's privte member whenever what inheritence is used
};

class PrivateDerived: private Base{
public:
    PrivateDerived(int val_pub, int val_pro, int val_pri):
        Base(val_pub, 
            val_pro,
            val_pri)
    {

    }
    ~PrivateDerived(){}

    int priGetBasePub() { return valPub; }
    int priGetBasePro() { return valPro; }
    // int priGetBasePri() { return valPri; }   // cat not get base's privte member whenever what inheritence is used
};


int main(void)
{
    PublicDerived       pubObj(1,2,3);
    ProtectedDerived    proObj(4,5,6);
    PrivateDerived      priObj(7,8,9);

    
    std::cout << pubObj.pubGetBasePub() << std::endl;
    std::cout << proObj.proGetBasePub() << std::endl;   
    std::cout << priObj.priGetBasePub() << std::endl;
    std::cout << pubObj.pubGetBasePro() << std::endl;
    std::cout << proObj.proGetBasePro() << std::endl;   
    std::cout << priObj.priGetBasePro() << std::endl;

    /* base's public member only can be accessed by a public derived class's obj */
    std::cout << pubObj.valPub << std::endl;
    // std::cout << proObj.valPub << std::endl;    // error 
    // std::cout << priObj.valPub << std::endl;    // error

    /* no obj can get the base's protected member even when it is base's obj */
    // std::cout << pubObj.valPro << std::endl; // error
    // std::cout << proObj.valPro << std::endl; // error
    // std::cout << priObj.valPro << std::endl; // error

    /* no obj can get the base's private member even when it is base's obj */
    // std::cout << pubObj.valPri << std::endl; // error
    // std::cout << proObj.valPri << std::endl; // error
    // std::cout << priObj.valPri << std::endl; // error
    

    

    return 0;
}
