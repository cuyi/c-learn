#include <iostream>
#include <utility>

//  ref == lvalue_ref
// 右值引用只能绑定到一个将要销毁的对象
int main(void)
{
    int i = 42; // i is a lvalue
    int &r = i; // r is a lvalue reference
    //  int &&rr = i; // wrong: can not bind a lvalue to a rvalue_ref
    //  int &r2 = i * 42;   // wrong: i*42 is rvaule, can not bind a rvalue to a lvalue_ref
    const int &r2 = i * 42; // right: can bind a rvalue to a const ref
    int &&rr2 = i * 42;

    
    int &&rr3 = 88;
    //int &&rr4 = rr3; // wrong: rr3 is variable of rvalue_ref type, so is variable, so is a lvalue
    int &&rr4 = std::move(rr3);
    std::cout << rr4 << std::endl;
    // you'd better not use rr3 from now on, except assignment and destroy.
    return 0;
}
