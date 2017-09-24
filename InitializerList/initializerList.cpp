#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/*  // 类类型成员的构造
struct Test1
{
    Test1() // 无参构造函数
    { 
        cout << "Construct Test1" << endl ;
    }

    Test1(const Test1& t1) // 拷贝构造函数
    {
        cout << "Copy constructor for Test1" << endl ;
        this->a = t1.a ;
    }

    Test1& operator = (const Test1& t1) // 赋值运算符
    {
        cout << "assignment for Test1" << endl ;
        this->a = t1.a ;
        return *this;
    }

    ~Test1()
    {
        cout << "deconstructor Test1" << endl;
    }
    int a ;
};

struct Test2
{
    Test1 test1 ;
    Test2(Test1 &t1)
    {
        test1 = t1 ;
    }
};
*/

/* will not pass the compile, because Test1 do not have a default constructor
struct Test1
{
    Test1(int a):i(a){}
    int i ;
};

struct Test2
{
    Test1 test1 ;
    Test2(Test1 &t1)
    {
        test1 = t1 ;
    }
};
*/

struct Test1
{
    Test1(int a):i(a){}
    int i ;
};

struct Test2
{
    Test1 test1 ;
    Test2(Test1 &t1):test1(t1)
    {
        
    }
};

// 成员是按照他们在类中出现的顺序进行初始化的，而不是按照他们在初始化列表出现的顺序初始化的
struct foo{
    int i;
    int j;
    foo(int x):i(x), j(i){}
    //foo(int x):j(x), i(j){} this will caused to non-predicated i value.
};
int main(void)
{
    Test1 t1(1);
    Test2 t2(t1);

    foo foobj(4);
    cout << foobj.i << endl;
    cout << foobj.j << endl;
    return 0;
}


