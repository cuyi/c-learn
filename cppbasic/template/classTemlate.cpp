#include <iostream>

template<typename T>
class theclass{
public:
    theclass() = default;
    theclass(T x):vale(x){}
    
private:
    T value;
};

// �����Ƿ�����һ��ģ����Ķ��󣬶�����ͨ����ʽʵ������������ģ��ʵ����
template class theclass<int>;








