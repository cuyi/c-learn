#include <iostream>
#include <cstdint>

class foo{
public:
    foo(){}
    foo(uint32_t inVal):val(inVal){}
    uint32_t getVal() const { return val; }
private:
    const uint32_t val{9};

};

int main(void)
{
    foo obj;
    std::cout << obj.getVal() << std::endl;
    foo obj1(888);
    std::cout << obj1.getVal() << std::endl;

    return 0;
}
