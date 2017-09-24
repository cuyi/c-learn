#include <iostream>
#include <functional>

#include <set>
#include <string>

using namespace std;

// FuncObjType 类重载了()运算符
class FuncObjType  
{  
public:  
    void operator() ()  
    {  
        cout<<"Hello C++!"<<endl;  
    }  
};

/*
void val()
{
    cout << "Hello C+_+!" << endl;
}
*/


/**********************************/
class StringSort  
{  
public:  
    bool operator() (const string &str1, const string &str2) const  
    {  
        return str1 > str2;  
    }  
};


int main(int argc, char *argv[])
{
    FuncObjType val;
    
    val();

    //set<string, StringSort> myset;
    set<string, std::greater<string>> myset;
    myset.insert("A");
    myset.insert("B");

    for(const auto e : myset)
        cout << e << endl;
    
    return 0;
}
