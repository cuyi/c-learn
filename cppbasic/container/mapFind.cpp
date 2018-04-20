#include <iostream>
#include <map>
#include <numeric>
#include <limits> // numeric_limits
#include <algorithm>

#include <cstdint>
#include <cstring>  // memset()

class map_finder{
public:
    map_finder(const std::uint8_t &lcId):m_lcId(lcId){}

    bool operator()(const std::multimap<uint8_t, uint8_t>::value_type &pair)
        {
        return pair.second == m_lcId;
    }
    
private:
    const std::uint8_t &m_lcId;
};

int main(void)
{
    std::multimap<uint8_t, uint8_t, std::greater<uint16_t>> aToB;

    aToB.emplace(std::make_pair(5, 4));
    aToB.emplace(std::make_pair(3, 3));
    aToB.emplace(std::make_pair(1, 6));

    uint8_t lcId = 4;
    auto iter = aToB.begin();
    /* 
    this works well
    if( aToB.end() != std::find_if(aToB.begin(), aToB.end(), map_finder(lcId)))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    */ 

    // this works well too
    if( aToB.end() != std::find_if(aToB.begin(), aToB.end(), [&](const std::multimap<uint8_t, uint8_t>::value_type &pair){return pair.second == lcId;}))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    
    return 0;
}

