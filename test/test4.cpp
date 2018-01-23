#include <iostream>
#include <cstdint>

class foo{
public:
    foo(){}
    //uint8_t getVal(){ return val; }
    uint8_t& getVal(){ std::cout << "non const called\n"; return val; }
    const uint8_t& getVal() const { std::cout << "const called\n"; return val; }
private:
    uint8_t val{78};
};

int main(void)
{
    foo obj;
    const foo* p = &obj;
    std::cout << p->getVal() << std::endl;
    foo* p2 = &obj;
    p2->getVal() = 99;
    std::cout << p2->getVal() << std::endl;
}
