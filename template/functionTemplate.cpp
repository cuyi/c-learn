/*
 * 对函数模板的使用而言，分为两种调用方式，
 * 一种是显示模板实参调用（显示调用），
 * 一种是隐式模板实参调用（隐式调用）。
 * 对于类模板的使用而言，没有隐式模板实参和显式模板实参使用的说法，因为类模板的使用必须显示指明模板实参
 */

#include <iostream>

template<typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
    if(f(v1, v2)) return -1;    // v1 < v2 , -1
    if(f(v2, v1)) return 1;     // v1 > v2 , 1
    return 0;                   // v1 = v2 , 0
}

/* 
 *  不管是否发生函数调用，都可以通过显示实例化 声明 将函数模板实例化 
 *  template int compare<int>(const int &v1, const int &v2, std::less<int> f);
 */

// This a funciont template explicit function definition  函数模板显式特化
// default argument specified in explicit specialization is not allowed
template<> int compare<int>(const int &v1, const int &v2, std::less<int> f)
{
    if(f(v1, v2)) return -1;    // v1 < v2 , -1
    if(f(v2, v1)) return 1;     // v1 > v2 , 1
    return 0;                   // v1 = v2 , 0
}

template <typename T>
void func(T t)
{
    std::cout << t << std::endl;
}

void invoke(void (*p)(int))
{
    int num = 10;
    p(num);
}


/*
 * 用于展示显式模板实例化的必要性
 */
template <typename T> T Max(const T& t1, const T& t2)
{
    return (t1  >t2) ? t1 : t2;
}

int main(void)
{
    int ret = compare<int>(1, 2);   // 函数模板显示实例化
    // int ret = compare(1, 2);     // 函数模板隐式实例化

    std::cout << ret << std::endl;

    invoke(func);                   // 函数模板隐式实例化
    invoke(func<int>);              // 函数模板显示实例化

    int i=5;
    //std::cout << Max(i,'a') << std::endl; //无法通过编译 : error: no matching function for call to Max(int&, char)
    std::cout << Max<int>(i,'a') << std::endl; //显示调用，通过编译

    return 0;
}
