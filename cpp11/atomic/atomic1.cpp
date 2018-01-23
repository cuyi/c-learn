#include <iostream>
#include <atomic>

using namespace std;

int main(void)
{
    std::atomic<uint32_t> val;
    val.store(3);
    cout << val << endl;
    cout << val.load() << endl;
    
    val.fetch_add(2);
    cout << val.load() << endl;
}
