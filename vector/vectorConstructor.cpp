#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Foo{
public:
    Foo(int val):val_{val}
    {}

    int getVal()
    {
        return val_;
    }
private:
    int val_;
};


int main(void)
{
    uint8_t numberOfDrb{5};
    std::vector<uint8_t> testQueueTimeOfRlcPduVec(numberOfDrb, 0XFF);
    uint32_t tempCount{0};
    for(auto e : testQueueTimeOfRlcPduVec)
    {
        printf("%d ", e);
        e == 255 ? tempCount++ : tempCount;        
    }
    std::cout << "tempCount = " << tempCount << std::endl;

    std::cout << "-------------------\n";
    Foo obj1(1);
    std::cout << obj1.getVal() << std::endl;

    Foo obj2{2};
    std::cout << obj2.getVal() << std::endl;
    
    Foo arrayObj[3]{4,5,6};
    std::cout << arrayObj[0].getVal() << std::endl;        
    std::cout << arrayObj[1].getVal() << std::endl;        
    std::cout << arrayObj[2].getVal() << std::endl;        

    printf("%d", sizeof(bool));
    return 0;
}
