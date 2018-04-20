#include <iostream>
/*
 * 指针变量在符号表上对应的地址值为指针变量的地址值，
 * 而引用在符号表上对应的地址值为引用对象的地址值。
 * 符号表生成后就不会再改，
 * 因此指针可以改变指向的对象（指针变量中的值可以改），而引用对象不能改。
 */

class D{
public:
    D(int a);
    D(const D& dobj);

    int m_b[10000];
};

D::D(int a){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = a;
    }
}

D::D(const D& dobj){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = dobj.m_b[i];
    }
}

int main(void)
{
    D dobj(1);
    D& refobj = dobj;

    if(&refobj == &dobj)
    {
        std::cout << "refobj and dobj have the same address in memory\n";
        
        if(&refobj.m_b[888] == &dobj.m_b[888])
            std::cout << "the member of  refobj and dobj have the same address in memory" << std::endl;
        else
            std::cout << "impossible\n";
    }

    return 0;
}


