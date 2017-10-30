#include <iostream>

using namespace std;

class foo{
public:
    foo(int r, double w):roots(r), weight(w){}
private:
    int roots;
    double weight;
};

int main(void)
{
    int x = 3;
    int x1 = {3};
    int x2(3);
    cout << x << " " << x1 << " " << x2 << endl;

    short arr[5] = {1, 2, 3, 4, 5};
    short arr1[5]{1, 2, 3, 4, 5};
    short *parr = new short[5]{1, 2, 3, 4, 5};
    cout << arr[2] << " " << arr1[2] << " " << parr[2] << endl;

    foo f1(2, 3.3);
    foo f1ok(2.2, 3.3);
    // foo f1wrong{2.2, 3.3}; c++11 don't allow down cast when using {} to initialize
    foo f2{2, 3.3};
    foo f3 = {2, 3.3};

    return 0;
}
