#include <iostream>
#include <string.h>

using namespace std;

class A
{
public:
		// constructor
		A(int i = 0)
		{
			a = i;
		}
		// interface to outside world
		void add(int num)
		{
			a += num;
		}
		// interface to outside world
		int get()
		{
			return a;
		}

private:
		// hidden data from outside world
		int a;
};


int main()
{ 
	A a(9); 
	a.add(10);
    std::cout << a.get() << std::endl;
	return 0;
}
