#include <iostream>
#include <cstring>

class CxString
{  
public:  
    char *_pstr;  
    int _size;  
    explicit CxString(int size)  // ʹ�� explicit ��������һ�������Ĺ��캯������ʿת��
    {  
        _size = size;
        _pstr = (char *)malloc(size + 1);
        memset(_pstr, 0, size + 1);
        std::cout << "constructor 1" << std::endl;
    }  
    CxString(const char *p)  
    {  
        int size = strlen(p);  
        _pstr = (char *)malloc(size + 1);
        strcpy(_pstr, p);
        _size = strlen(_pstr);  
        std::cout << "constructor 2" << std::endl;
    }  
    
};  
  
CxString string1(24);     
//CxString string2 = 10; // �ڲ�ʹ�� explicit��ʱ������൱�� CxString temp(10); string(temp) ;// ����ʹ���˱�����Ϊ�����ṩ��Ĭ�ϵĸ��ƹ��캯��
//CxString string3;      //���ṩ�޲εĹ��캯������Ǳ��벻����   
CxString string4("aaaa"); 
CxString string5 = "bbb"; 
//CxString string6 = 'c';   


int main(void)
{
    return 0;
}
