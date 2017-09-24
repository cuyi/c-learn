/*
 类模板特化类似于函数模板的特化，即类模板参数在某种特定类型下的具体实现。考察如下代码。
 */

#include <iostream>
using namespace std;

template<typename T>class A{
    T num;
public:
    A(){
        num=T(6.6);
    }
    void print(){
        cout<<"A'num:"<<num<<endl;
    }
};

template<>class A<char*>{
    char* str;
public:
    A():str("hahaha\n"){}
    void print(){
        cout<<str<<endl;
    }
};

int main(){
    A<int> a1;      //显示模板实参的隐式实例化
    a1.print();
    A<char*> a2;    //使用特化的类模板
    a2.print();
}