#include <iostream>
/*
 * ָ������ڷ��ű��϶�Ӧ�ĵ�ֵַΪָ������ĵ�ֵַ��
 * �������ڷ��ű��϶�Ӧ�ĵ�ֵַΪ���ö���ĵ�ֵַ��
 * ���ű����ɺ�Ͳ����ٸģ�
 * ���ָ����Ըı�ָ��Ķ���ָ������е�ֵ���Ըģ��������ö����ܸġ�
 */

class D{
public:
    D(int a);
    D(const D& dobj);

    int m_b[10000];
};

D::D(int a){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = a;
    }
}

D::D(const D& dobj){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = dobj.m_b[i];
    }
}

int main(void)
{
    D dobj(1);
    D& refobj = dobj;

    if(&refobj == &dobj)
    {
        std::cout << "refobj and dobj have the same address in memory\n";
        
        if(&refobj.m_b[888] == &dobj.m_b[888])
            std::cout << "the member of  refobj and dobj have the same address in memory" << std::endl;
        else
            std::cout << "impossible\n";
    }

    return 0;
}


