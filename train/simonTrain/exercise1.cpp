#include <iostream>
#include <vector>
#pragma pack(8) 


/* ���ʵ���������ڴ��з���һ���ַ��ÿ��ʵ�����ڴ��ж��ж�һ�޶��Ķ���ַ��
   ͬ��������Ҳ��ʵ���������Ա���������������������һ���ֽڣ�
   ��������ʵ��������ж�һ�޶��ĵ�ַ�ˡ����ԣ������sizeofΪ1��������0.
 */
class A{};

class B{
public:
    int a[2];
};

class C{
public:
    int *b[2];
};

class D: public B, public C{
public:
    int dd;
};
int main(void)
{
    A aobj;
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "sizeof(aobj) = " << sizeof(aobj) << std::endl;

    B bobj;
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(bobj) = " << sizeof(bobj) << std::endl;

    C cobj;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
    std::cout << "sizeof(cobj) = " << sizeof(cobj) << std::endl;

    D dobj;
    std::cout << "sizeof(D) = " << sizeof(D) << std::endl;
    std::cout << "sizeof(dobj) = " << sizeof(dobj) << std::endl;
    std::cout << "sizeof(D*) = " << sizeof(D*) << std::endl;

    B* bPtr = new B;  
    D* dPtr = (D*)bPtr;

    std::cout << dPtr->dd << std::endl;
    std::cout << dPtr->a[1] << std::endl;
    
    
    
    
    return 0;
}

