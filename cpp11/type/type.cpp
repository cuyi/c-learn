#include <iostream>
#include <iomanip>
#include "../../utility/bits.hpp"

using namespace std;

int main(void)
{
    cout << "program bits = " << getProgramBits() << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(char16_t) = " << sizeof(char16_t) << endl;
    cout << "sizeof(char32_t) = " << sizeof(char32_t) << endl;
    return 0;
}
