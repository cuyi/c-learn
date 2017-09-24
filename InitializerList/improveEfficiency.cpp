/*
 * 初始化成员列表可提升性能
 */

#include <iostream>


class Test3 {  
  
public:  
  
    int a;  
  
    Test3() {  
  
        a = 0;  
  
        puts("Test3 constructor");  
  
    }  
  
    Test3(Test3 &t3) {  
  
        this->a = t3.a;  
  
        puts("Test3 copy constructor");  
  
    }  
  
    Test3& operator=(Test3 &t) {  
  
        puts("Test3 assign operator");  
  
        this->a = t.a;  
  
        return *this;  
  
    }  
  
  
  
    ~Test3() { }  
  
};  
  
  
  
class Test4 {  
  
public:  
  
    Test3 t3;  

    // This will just lead only one Test3 copy constructor
    // initializerlist is more efficiency
    Test4( Test3 &t3) : t3(t3) { //这种方式和下面的方式有相同的效果，不同的效率  
    }  

    // This will lead to one Test3 constructor and one Test3 assign operator
    //Test4( Test3 &t3) {    
    //    this->t3 = t3;  
    //};
  
};  

int main(void)
{
    Test3 t3;
    Test4 t4(t3);
    
    return 0;
}

