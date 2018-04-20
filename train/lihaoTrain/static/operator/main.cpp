#include <iostream>


class complex
{
public:

    complex() { real = imag = 0; }

    complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    complex operator +(const complex &c);

    //complex operator -(const complex &c);
    //complex operator *(const complex &c);
    //complex operator /(const complex &c);

    void print()
    {
        if(imag < 0)
        {
            std::cout << real << imag << 'i' << std::endl;
        }
        else
        {
            std::cout << real << '+' << imag << 'i' << std::endl;
        }
    }

private:
    double real, imag;
};


inline complex complex::operator +(const complex &c)
{
    return complex(this->real + c.real, this->imag + c.imag);
}



int main()
{
    complex c1(2.0, 3.0), c2(4.0, -2.0);

    std::cout << "c1 = ";
    c1.print();

    std::cout << "c2 = ";
    c2.print();
    
    std::cout << "c1 + c2 = ";
    (c1 + c2).print();


    return 0;
}
