/*
    protected constructor & destructor ʹ�����ֻ�ܳ�Ϊ���࣬
    �Ҹû���Ĺ���ֻ��ͨ�������������С�
*/
#include <iostream>

class A{
protected:
    //A() = default;
    A(int p){ m_a = p; }
    ~A(){}
public:
    static A* createInstance(){ if(pInstance == NULL) pInstance = new A(88); return pInstance;}
    int getVal() const { return m_a; }
private:
    static A *pInstance;
    int m_a;
};

class B: public A{
public:
    /*
        ������ֻ�ṩ�˴��������з�Ĭ�ϲ����Ĺ��캯����
        ��ô���������ʽ���û���Ĺ��캯�������๹��
        �����Ĳ���ͨ������Ĺ��캯�����βδ���
    */
    B(int cc):A(cc), m_val(cc){}   
    ~B(){}
private:
    int m_val;
};


A* A::pInstance = nullptr;
int main(void)
{
    //A a;
    B b(9);
    A*  pToa = B::createInstance();
    std::cout << pToa->getVal();
    
    return 0;
}
