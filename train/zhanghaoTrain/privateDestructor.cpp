/*
    �涨��ֻ���ڶ��Ϸ����ڴ�ʱ���Խ�������������Ϊprivate
    �������ջ�Ļ��뿪�������ʱ����Զ�����������������ʱ���д���
    һ����ṩһ��destroy�ⲿ��
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
