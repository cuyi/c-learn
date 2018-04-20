#include <iostream>

int main()
{
	int a = 1;
	int &b = a;
	b=2;
	std::cout<<a<<std::endl; //a=2,b=2
	int c = 3;
	b = c;
	std::cout<<a<<std::endl; //a=3,b=3

	//int &d;
	
	
}

