#include <iostream>

using namespace std;

int getVal(int x)
{
    return (x+3);
}

int main(void)
{
    // Use auto when you need a local copy. This will never produce a reference.
    auto val = getVal(3);
    
    // Use auto&& when you don't care if the object is local or not. 
    // Technically, this will always produce a reference, but if the 
    // initializer is a temporary (e.g., the function returns by value), 
    // it will behave essentially like your own local object.
    auto &&val2 = getVal(3);
    
    // auto& guarantees that you are sharing the variable with something 
    // else. It is always a reference and never to a temporary.
    // auto &val3 = getVal(3); // WRONG: a reference never to a temporary
    
    // const auto& like auto&&, but provides read-only access.
    const auto &val4 = getVal(3);
}