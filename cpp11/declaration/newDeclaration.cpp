#include <iostream>

using namespace std;

double fm(double, int)
{
    ; // do nothing
}

// 返回类型后置
auto fm1(double, int) -> double
{
    // do something
    return 2.3;
}

// 模板 & decltype & 后置返回类型
template<typename T, typename U>
auto eff(T t, U u) -> decltype(T * U)
{
    // do something
}

int main(void)
{
    // 让编译器自动推导类型
    auto i = 112;   // int
    auto p = &i;    // int*
    auto pf = fm;   // double(*)(double, int)
    
    // 将变量类型指定为表达式的类型
    decltype (i) y; // 将y设置为与i相同的类型
    y = 45;
    cout << y << endl;

    auto ret = fm1(4.5, 5);
    cout << ret << endl;
    return 0;
}
