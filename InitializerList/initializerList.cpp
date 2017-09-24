#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/*  // �����ͳ�Ա�Ĺ���
struct Test1
{
    Test1() // �޲ι��캯��
    { 
        cout << "Construct Test1" << endl ;
    }

    Test1(const Test1& t1) // �������캯��
    {
        cout << "Copy constructor for Test1" << endl ;
        this->a = t1.a ;
    }

    Test1& operator = (const Test1& t1) // ��ֵ�����
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

// ��Ա�ǰ������������г��ֵ�˳����г�ʼ���ģ������ǰ��������ڳ�ʼ���б���ֵ�˳���ʼ����
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


