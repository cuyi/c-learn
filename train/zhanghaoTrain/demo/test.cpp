#include <iostream>

class A
{
public:
	A(){}	
	void destroy()
	{
		delete this;
	}
private:
	~A(){}
};

int main()
{
	A a;
	A* ap = new A();
	ap->destroy();
}