#include <iostream>

class Print{
public:
    void operator()(int n)
        {
        std::cout << n << std::endl;
        return ;
    }
};

int main(void)
{
    Print printObj;
    printObj(444);
    printObj.operator()(555); // explicit call a function obj

    return 0;
}
