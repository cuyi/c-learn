#include <iostream>

class A
{
public:
	A()	{	}
	
	void fun(int a)
	{
		std::cout<<"fun int."<<std::endl;
	}
	void fun(double a)
	{
		std::cout<<"fun double."<<std::endl;
	}
	int operator+(int a)
	{
		return a*2;
	}
};


int main()
{
	A a;
	a.fun(1);
	a.fun(1.1);
int b=	a+9;
std::cout<<"fun "<<b<<std::endl;
	return 0;
}
