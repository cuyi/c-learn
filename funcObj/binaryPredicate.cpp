/*
 * Predicate 谓词函数，通常用来对传入的参数进行判断，并返回bool值
 * Predicate 可以简单分为 UnaryPredicate， BinaryPredicate.  即传入的参数为1个，2个。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This is a UnaryPredicate
class NoLess{
public:
    NoLess(int min = 0):m_min(min){}

    bool operator() (int value) const
    {
        return value >= m_min;
    }

private:
    int m_min;
};

// This is a BinaryPredicate
// Objects of class type which are callable are called function objects 
// Infact, these classes have overloaded operator(). This make it callable.

std::greater<int> bp;
bool isGreater = bp(1, 2);

// UnaryPredicate with internal state
//
class Nth
{
public:
	Nth(int n=0):m_nth(n),m_count(1){}
	bool operator() (int)
	{
		return m_count++ == m_nth;
	}
	
	int GetCount()const
	{
		return m_count;
	}
	
private:
	int m_nth;
	int m_count;
};

// Our own remove_if, this will behave like what you thinked
template<class ForwardIt, class UnaryPredicate>  
ForwardIt remove_if(ForwardIt first, ForwardIt last,   
                          UnaryPredicate p)  
{  
    ForwardIt result = first;  
    for (; first != last; ++first) {  
        if (!p(*first)) {  
            *result++ = *first;  
        }  
    }  
    return result;  
}


int main(void)
{
    vector<int> ivec;
    for(int i = 0; i < 10; ++i)
        ivec.push_back(i);

    vector<int>::iterator iter = ivec.begin();
    iter = find_if(ivec.begin(), ivec.end(), NoLess(5));
    cout << *iter << endl;

    if(isGreater)
        cout << "1>2 is true" << endl;
    else
        cout << "1>2 is false" << endl;

    Nth nth(3);
    vector<int>::iterator nthItr = find_if(ivec.begin(), ivec.end(), nth);
    cout << "3rd: " << *nthItr << endl;
    cout << "State: " << nth.GetCount() << endl; // here you will find the nth's m_count is still 1.

    vector<int> vec;  
    for(vector<int>::size_type i=0; i<10; ++i)  
        vec.push_back(i+1);  
    
    // Use the global remove_if instead of the STL's, 
    // Or it will print 1,2,4,5,7,8,9,10,9,10 instead of 1,2,4,5,6,7,8,9,10,10
    ::remove_if(vec.begin(),vec.end(),nth);  
          
    for(vector<int>::size_type i=0; i<10; ++i)  
    {  
        cout<<vec[i]<<endl;  
    }
    
    return 0;
}
