/*
    规定类只能在堆上分配内存时可以将析构函数声明为private
    如果是在栈的话离开作用域的时候会自动调用析构函数，此时会有错误。
    一般会提供一个destroy外部接
*/

#include <iostream>

class PrivateDestructor{
public:
    PrivateDestructor() = default;
    void destroy(){ delete this; }

private:
    ~PrivateDestructor() = default;
};

int main(void)
{
    //PrivateDestructor obj1;   // can not make a obj on stack space
    PrivateDestructor* pobj2 = new PrivateDestructor;   // through new operator we can create a n obj on heap

    pobj2->destroy();   // do the 
    return 0;
}
