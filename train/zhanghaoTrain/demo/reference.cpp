//引用于指针的区别？
#include <iostream>
#include <string.h>

struct Point
{
	int a;
};

class A
{
public:	
	A(){ std::cout << "constructor" << std::endl; }
	A(int aa){m_Point.a=aa;}
	A& operator = (const A& other)
	{
		m_Point=other.m_Point;
        std::cout << "assignment constructor called" << std::endl;
		return *this;
	}

    A(const A& other)
    {
        m_Point = other.m_Point;
        std::cout << "copy constructor called" << std::endl;
    }
    
	void add(Point& point)
	{
        point.a++;
	}
	
	void print1(Point& point)
	{
        std::cout<<"point=  "<<point.a<<std::endl;
	}
	
	void print2()
	{
        std::cout<<"m_Point=  "<<m_Point.a<<std::endl;
	}
	
	Point m_Point;
};


A fooFun(A val)
{
    std::cout << "start\n";
    A temp(val);
    std::cout << "stop\n";
    return temp;
}

A fooFun2()
{
    A temp(888);
    return temp;
}

int main()
{
	A a(10);
	Point point={0};
	a.print1(point);
	a.add(point);
	a.print1(point);
	
	A b, c;
    b=c=a;
	a.print2();
	b.print2();
	c.print2();

    A d = fooFun(a);    // 此处在fooFun中的临时对象以值的方式返回时并不会调用拷贝构造函数，因为 d 
    d.print2();

    A e;
    e = fooFun2();
    e.print2();
	
	return 0;
}