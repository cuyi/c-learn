#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
using namespace std;


int main()
{
   array<int,5> hightA = {100,200,300,400,500};
   vector<int> hightV;

   long tickStart = clock();
    for (int i = 0; i < 10000; i++ )
    {
        hightV.push_back(hightA[i%5]);
    }

    long tickEnd = clock();  
	cout << "tickStart = " << tickStart << endl;  
    cout << "tickEnd = " << tickEnd << endl;  
    cout << "push_back 10000 times time takes = " << tickEnd - tickStart << endl;  

    tickStart = clock();
    for (int j = 0; j < 5; j++ )
    {
        hightV.remove(hightA[i]);
    }
    tickEnd = clock();  

	cout << "tickStart = " << tickStart << endl; 
    cout << "tickEnd = " << tickEnd << endl;  
    cout << "remove 10000 times time takes = " << tickEnd - tickStart << endl;  

     return 0;
}

