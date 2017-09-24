#include <iostream>

template<typename T>
class theclass{
public:
    theclass() = default;
    theclass(T x):vale(x){}
    
private:
    T value;
};

// 不管是否生成一个模板类的对象，都可以通过显式实例化声明将类模板实例化
template class theclass<int>;








