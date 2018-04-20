#include <iostream>
#include <string.h>

class A
{
public:
	A()
	{
		std::cout<<"class A default Constructor."<<std::endl;
	}
	A(const A& a)
	{
		std::cout<<"class A copy Constructor."<<std::endl;
	}
	A& operator= (const A& a)
	{
		std::cout<<"class A assignment operator."<<std::endl;
		return *this;
	}
	~A()
	{
		std::cout<<"class A destructor."<<std::endl;
	}
};

class B : private A
{
public:
	B()
	{
		std::cout<<"class B default Constructor."<<std::endl;
	}
	B(const B& b)
	{
		std::cout<<"class B copy Constructor."<<std::endl;
	}
	B& operator=(const B& b)
	{
		std::cout<<"class B assignment operator."<<std::endl;
		if (this != &b)
			A::operator=(b);
		return *this;
	}
	~B()
	{
		std::cout<<"class B destructor."<<std::endl;
	}
};


int main()
{
	B b1,b2;
	
	b2=b1;
	B b3(b1);
	B* b4=new B();
	delete b4;
	
	return 0;
}