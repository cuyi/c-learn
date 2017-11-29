/*
    this test show that we can call a class's static member
    with out instantiation this class.
*/

#include <iostream>
#include <vector>

using namespace std;

class foo{
public:
    foo();
    static void print()
    {
        std::cout << "haha" << std::endl;
        //std::cout << value << std::endl;
    }
private:
    static uint32_t value;
    uint32_t value2;
};

//uint32_t foo::value = 9;

int main(void)
{
    foo::print();
    
    return 0;
}
