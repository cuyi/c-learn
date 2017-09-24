/*
 *
 使用普通函数重载和使用模板特化还是有不同之处，主要表现在如下两个方面： 
（1）如果使用普通重载函数，那么不管是否发生实际的函数调用，都会在目标文件中生成该函数的二进制代码。
    而如果使用模板的特化版本，除非发生函数调用，否则不会在目标文件中包含特化模板函数的二进制代码。这符合函数模板的“惰性实例化”准则。
（2）如果使用普通重载函数，那么在分离编译模式下，应该在各个源文件中包含重载函数的申明，否则在某些源文件中就会使用模板函数，而不是重载函数。
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

template<typename T> T Max(T t1,T t2){
    return (t1>t2)?t1:t2;
}

typedef const char* CCP;
// 函数模板特化的定义
template<> 
CCP Max<CCP>(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

// 除了定义函数模板特化版本外，还可以直接给出模板函数在特定类型下的重载形式（普通函数）
CCP Max(CCP s1, CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

int main(){
    //调用实例：int Max<int>(int,int)
    int i=Max(10,5);
    //调用显示特化：const char* Max<const char*>(const char*,const char*)
    const char* p=Max<const char*>("very","good");
    cout<<"i:"<<i<<endl;
    cout<<"p:"<<p<<endl;
}

