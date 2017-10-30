#include <iostream>
#include <vector>

class SmallInt
{
public:
    SmallInt(int i = 0): value_(i)
    {
        std::cout << "constructor called\n";
        if( i < 0 || i > 255 )
            throw std::out_of_range("Bad SmallInt value");
    }

    /*
    		conversion operator 是类的一个特殊成员函数：
    		负责将一个类类型的值转化为其他类型。
    		1. 不能声明返回类型，
    		2. 形参列表也必须为空。
    		3. 通常应该是const
    */
    operator int() const
    {
    	std::cout << "conversion operator called: operator int() const \n";
        return value_;
    }
    
    SmallInt& operator=(const SmallInt& other)
    {
        std::cout << "assignment operator overload called\n";	
        if(this != &other)
        {	
            this->value_ = other.value_;
            // *this = other;   this will cause Segmentation fault
        }
        return *this;	
    }
    
private:
    std::size_t value_;
};

int main(void)
{
    SmallInt si;
    std::cout << __LINE__ << std::endl;
    si = 4;
    
    std::cout << __LINE__ << std::endl;
    int b = si + 4;
    std::cout << __LINE__ << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}

