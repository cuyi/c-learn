#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    uint8_t a[8];
    uint8_t b[8];

    memset(&a, 255, sizeof(a));

    memcpy(&b, &a, sizeof(b));

    int c[10];

    cout << sizeof(c) << endl;

    cout << sizeof(c)/sizeof(int) << endl;

    return 0;
}
