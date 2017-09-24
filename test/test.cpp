#include <iostream>


// An implicitly-declared default constructor is an inline  public member of its class...

class test{
//public:
//    test()=default;

public:
    int getMember()
    {
        return this->a;
    }

private:
    int a{0};
};


class B1
{
    int a;
    int b;
    int c;
    int d;
};

class B2
{
    int a;
    int b;
    int c;
    int d;
    int &e=d;
};

int main(void)
{
    test testObj;   // error, because the constructor is private
    std::cout << testObj.getMember() << std::endl;
    
    std::cout << "sizeof(B1)="<<sizeof(B1) <<" sizeof(B2)="<<sizeof(B2) <<std::endl;
    return 0;
}

