#include <iostream>
#include <map>
#include <numeric>
#include <limits> // numeric_limits

#include <cstdint>
#include <cstring>  // memset()

int main(void)
{
    std::multimap<uint8_t, uint8_t, std::greater<uint16_t>> aToB;
    std::map<uint8_t, uint8_t> bToA;

    aToB.emplace(std::make_pair(5, 4));
    aToB.emplace(std::make_pair(1, 5));
    aToB.emplace(std::make_pair(1, 3));

    for(auto iter = aToB.begin(); iter != aToB.end(); ++iter)
        bToA.emplace(std::make_pair(iter->second, iter->first));

    

    uint8_t sequence[12];

    memset(&sequence, std::numeric_limits<uint8_t>::max(), sizeof(sequence));
    
    auto iter = aToB.begin();
    unsigned i = 0;
    while(bToA.size() != 0 )
    {
        if(bToA[iter->second]){
            sequence[i++] = iter->second;
            bToA[iter->second]--;
        }

        if(bToA[iter->second] == 0)
            bToA.erase(iter->second);

        iter++;

        if(iter == aToB.end())
            iter = aToB.begin();
    }

    std::cout << "Hello Jingran" << std::endl;
        
    return 0;
}

