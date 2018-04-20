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

class B : private A
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
		void fun_c()
		{
			//c=0;
		}
};

class C : public B
{

};

int main()
{
	B b;
	//b.a=0;
	//b.b=0;
	//b.c=0;
	
	//b.fun();
	b.fun_a();
	b.fun_b();
	b.fun_c();

	C c;	
	return 0;
}
