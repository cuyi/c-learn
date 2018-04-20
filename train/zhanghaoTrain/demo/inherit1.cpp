#include <iostream>
#include <string.h>

class A
{
public:
	void fun()
	{
		a=0;
		b=0;
		c=0;
	}

public:
	int a;
protected:
	int b;
private:
	int c;	
};

class B : public A
{
	public:
		void fun_a()
		{
			a=0;
		}
		void fun_b()
		{
			b=0;
		}
		//void fun_c()
		//{
		//	c=0;
		//}
};


int main()
{
	A a;
	a.a=0;
	//a.b=0;
	//a.c=0;
	B b;
    b.a;
    // b.b; // error
	
	return 0;
}