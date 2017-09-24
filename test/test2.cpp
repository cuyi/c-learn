#include <iostream>

class Cat{
public:
    Cat() = default;
    Cat(const std::string s): s_(s)
    {
        std::cout << "Cat constructor\n";
    }

    std::string s_;
};

int main(void)
{
    std::string desp = "hello";
    Cat cat(desp);

    return 0;
}

