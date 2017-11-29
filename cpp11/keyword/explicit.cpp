#include <iostream>
#include <cstring>

class CxString
{  
public:  
    char *_pstr;  
    int _size;  
    explicit CxString(int size)  // 使用 explicit 可以抑制一个参数的构造函数的隐士转换
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
//CxString string2 = 10; // 在不使用 explicit的时候这句相当于 CxString temp(10); string(temp) ;// 这里使用了编译器为我们提供的默认的复制构造函数
//CxString string3;      //不提供无参的构造函数这句是编译不过的   
CxString string4("aaaa"); 
CxString string5 = "bbb"; 
//CxString string6 = 'c';   


int main(void)
{
    return 0;
}
