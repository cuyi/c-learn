#include <iostream>
#include <string.h>

class A
{
public:
	static void fun()
	{
		a=0;
		b=0;
		c=0;
	}

public:
	static int a;
protected:
	static int b;
private:
	static int c;	
};

class B : private A
{
public:
	void fun_a()
	{
		a++;
		std::cout<<"a="<<a<<std::endl;
	}
	void fun_b()
	{
		b++;
		std::cout<<"b="<<b<<std::endl;
	}
};

int A::a=0;
int A::b=0;
int A::c=0;

int main()
{
	B b;
	
	//b.fun();
	b.fun_a();
	b.fun_b();
	
	b.fun_a();
	b.fun_b();
	
	return 0;
}