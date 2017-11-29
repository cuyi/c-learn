#include <iostream>
#include <vector>
#include <utility>

int main(void)
{
    std::vector<std::pair<uint8_t, uint8_t>> vecPair;

    vecPair.push_back(std::make_pair(-1, 0));
    vecPair.push_back(std::make_pair(5, 101));

    std::cout << vecPair[0].first << " " << vecPair[0].second << std::endl;
    std::cout << vecPair[1].first << " " << vecPair[1].second << std::endl;
    
    std::cout << vecPair.size() << std::endl;

    uint8_t i = 5;
    while(i--)
        std::cout << "hi" << std::endl;

    return 0;
}

