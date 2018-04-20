#include <iostream>


#if 1

int sum(int a)
{
    return a;
}

#endif

int sum(int a, int b)
{
    return (a + b);
}



double sum(double a, double b)
{
    return (a + b);
}


int main()
{
    int a = 100, b = 50;
    double c = 100.1, d = 50.1;

 //   std::cout << a << " + " << b << " = " << sum(a, b) << std::endl;
 //   std::cout << c << " + " << d << " = " << sum(c, d) << std::endl;

    return 0;
}
