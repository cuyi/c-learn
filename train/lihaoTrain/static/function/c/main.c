#include <stdio.h>


int sum(int a, int b)
{
    return (a + b);
}

// c does not support Function Overload
double sum1(double a, double b)
{
    return (a + b);
}


int main()
{
    int a = 100, b = 50;
    double c = 100.1, d = 50.1;


    printf("%d + %d = %d \n", a, b, sum(a, b));
    printf("%lf + %lf = %lf \n", c, d, sum1(c, d));

    return 0;
}
