#include <iostream>
#include <climits>
#include <ctime>

using namespace std;

int main(void)
{
    std::srand(std::time(0));

    int ret = INT_MAX;
    ret = std::rand() % 40;

    cout << ret << endl;
    
    
    return 0;
}
