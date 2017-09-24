#include <iostream>

template <typename T> 
inline T sum(T const& a, T const& b) 
{
    return (a + b);
}

template <>
inline int sum(int const& a, int const& b)
{	
	std::cout << "specialize" << std::endl;
	return (a + b);
}

void doNothing()
{
	std::cout << "do nothing" << std::endl;

	asdfasdfsd
}


int main()
{
    int a = 100, b = 50;
    double c = 100.1, d = 50.1;
    float e = 100.1, f = 50.1;
    std::cout << a << " + " << b << " = " << sum(a, b) << std::endl;
    std::cout << c << " + " << d << " = " << sum(c, d) << std::endl;
   // std::cout << e << " + " << f << " = " << sum(e, f) << std::endl;
    (void)e;
	(void)f;
    return 0;
}
