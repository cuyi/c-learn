#include <iostream>
using namespace std;

int a =1;
int main()
{
    int a = 3;
    cout<<::a<<endl;  //���1
    cout<<a<<endl;   //���3
    return 0;
}

