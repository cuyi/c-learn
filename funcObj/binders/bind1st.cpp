// bind2nd(const Operation& op, const T& x): Return function object with second parameter bound
// bind1st(const Operation& op, const T& x): Return function object with first parameter bound

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> v;
    for(int i = 0; i < 1000; ++i)
        v.push_back(i);

    vector<int>::iterator iter;
    //iter = std::find_if(v.begin(), v.end(), bind1st(equal_to<int>(), 333));
    iter = std::find_if(v.begin(), v.end(), bind2nd(equal_to<int>(), 444));

    std::cout << *iter << std::endl;

    return 0;
}

