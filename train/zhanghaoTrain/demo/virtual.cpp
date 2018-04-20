#include <iostream>

class A
{
public:
	void print()
	{
		std::cout<<"A"<<std::endl;
	}
	
};

class B : public A
{
public:
	void print()
	{
		std::cout<<"B"<<std::endl;
	}
	
};

int main()
{
	A a;
	B b;
	a.print();
	b.print();
	
	A* ap=&b;
	ap->print();
	B* bp=&b;
	bp->print();
}