// g++ -std=c++11 generate.cpp
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class SuccessiveNumGen  
{  
public:  
    SuccessiveNumGen(int origin = 0):m_origin(origin){}  
    int operator() ()
    {  
        return m_origin++;  
    }  
private:  
    int m_origin;  
}; 


int main(int argc, char *argv[])
{
    vector<int> dest;

    generate_n(back_inserter(dest), 10, SuccessiveNumGen(3));

    for(const auto e : dest)
        cout << e << endl;
    
    
    return 0;
}

