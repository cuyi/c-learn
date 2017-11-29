#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// 使用 typedef 和 using 都可以创建别名，
typedef std::vector<std::string>::iterator itType;
using itType1 = std::vector<std::string>::iterator;

// 但是，两者之间的区别是：
// using 一个模板是可以，而 typedef 不可以
/* 下面 using 和 typedef 具体类型 */
using arr = std::array<int, 12>;
typedef std::array<int, 34> arr1;

/* 下面using 模板 ,而用typedef则不能实现一下功能 */
template<typename T>
using arrNew = std::array<T, 12>;

int main(void)
{
    arr myFixedSizeArray;
    cout << myFixedSizeArray.size() << endl;

    arr1 myFixedSizeArray1;
    cout << myFixedSizeArray1.size() << endl;

    arrNew<std::string> myFixedSizeArray2;
    cout << myFixedSizeArray2.size() << endl;
    return 0;
}
