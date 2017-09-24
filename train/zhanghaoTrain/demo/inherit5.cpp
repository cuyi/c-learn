#include <iostream>

class B
{
public:
	B()
	{
		std::cout<<"default Constructor."<<std::endl;
	}
	B(int b)
	{
		std::cout<<"normal Constructor."<<std::endl;
	}
	B(const B& b)
	{
		std::cout<<"copy Constructor."<<std::endl;
	}
	B& operator=(const B& b)
	{
		std::cout<<"assignment operator."<<std::endl;
		return *this;
	}
	~B()
	{
		std::cout<<"class destructor."<<std::endl;
	}
};


int main()
{
	B b1;
	B b2(1);
	
	b2=b1;
	B b3(b1);
	
	B* b4=new B;
	B* b5=new B();
	B* b6=new B(1);
	
	delete b4, b5, b6;

	
	return 0;
}
