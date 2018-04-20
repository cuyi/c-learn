#include <iostream>

class A{
public:
    int a;
    int b;
    void fun(){printf("this is A\n");}
    void printA() {printf("A's a is %d\n", a);}
};

class B: public A{
public:
    int c;
    void fun2();
};

void B::fun2 (){
    printf("this is B\n");
}

int main(void)
{
    A *obj1 = new A();
    B *bobj = new B();

    B* ptr = (B*)obj1;  //down cast: 父类指针强制转为指向其子类的指针  OK
    ptr->printA();
    ptr->fun();
    ptr->fun2();

    A *obj = bobj;
    obj->printA();
    obj->fun();
    //obj->fun2(); error // class A has no member named fun2
    
    return 0;
}

