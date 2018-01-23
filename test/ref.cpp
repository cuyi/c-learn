#include <iostream>

class foo{
public:
    foo(int val):val_{val}{}
    int getVal(){ return val_; }
    //int getVal() const { return val_; }

    void updateVal( int val) const {val_ = val; }
private:
    int val_;

};

int a;
int main(void)
{
    foo obj(88);
    std::cout << obj.getVal() << std::endl;

    obj.updateVal(99);
    std::cout << obj.getVal() << std::endl;

    // std::cout << obj.getVal() << std::endl;

}

