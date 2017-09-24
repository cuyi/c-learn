#include <iostream>
using namespace std;

int a =1;
int main()
{
    int a = 3;
    cout<<::a<<endl;  //Êä³ö1
    cout<<a<<endl;   //Êä³ö3
    return 0;
}

