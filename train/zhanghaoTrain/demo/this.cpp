#include <iostream>
#include <string.h>

class A
{
public:
	A(int a):b(a)
	{
	}
	
	void fun1()
	{
		std::cout<<"I am fun2"<<std::endl;
	}
	
	void fun2()
	{
		b=1;
		std::cout<<"I am fun4"<<std::endl;
	}

	void fun3()
	{
		std::cout<<"this: "<<this<<std::endl;
		std::cout<<"b: "<<this->b<<std::endl;
	}

private:
	int b;
};

	
int main()
{
	A a(1),b(2);
	a.fun3();
	b.fun3();
	
	A* ap = new A(0);
	A* bp = new A(0);
	ap->fun3();
	bp->fun3();
	
	A* pNull = NULL;
	
	pNull->fun1();
	pNull->fun2();
	
	return 0;
}