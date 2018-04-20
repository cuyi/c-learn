#include <memory>
#include <iostream>

/*
    unique_ptr:持有对对象的独有权:
        1. 两个unique_ptr 不可能指向同一个对象
        2. 不能进行复制操作只能进行移动操作
    unique_ptr指向的对象会被自动摧毁:
        1. 它指向的对象被破坏
        2. 对象通过 operator=() 或者 reset() 被指定到另一个指针
*/

int main(void)
{
    std::unique_ptr<int> p1(new int(2));
    *p1 = 5;
    std::cout << "*p1 = " << *p1 << '\n';
    
    //std::unique_ptr<int> p2 = p1; error

    // 转移所有权，现在那块内存归 p2 所有，p1成为无效指针
    std::unique_ptr<int> p2 = std::move(p1); 
    std::cout << "*p2 = " << *p2 << '\n';

    // after move, p1 is not a valid pointer, the follwing 
    // operation will cause segmentation fault
    // std::cout << "*p1 = " << *p1 << '\n'; 
    if(p1 == nullptr)
        std::cout << "p1 is nullptr now" << std::endl;
    else
        std::cout << "p1 is not valid pointer, either not a nullptr" << '\n';


    return 0;
}
