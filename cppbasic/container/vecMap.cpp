#include <iostream>
#include <vector>
#include <utility>
#include <map>

const uint8_t numOfUE = 10;
const uint8_t numOfDrbPerUe = 8;
int main(void)
{
    /*
    std::vector<std::map<uint8_t, uint32_t>> ueVecOfLcidToScheduleTimes;
    std::map<uint8_t, uint32_t> temp;
    for(uint8_t ueIndex = 0; ueIndex < numOfUE; ++ueIndex)
    {
        uint8_t startLcid = 3;
        for(uint8_t drbCount = 0; drbCount < numOfDrbPerUe; ++drbCount)
        {
            temp[startLcid++] = 0;
        }
        ueVecOfLcidToScheduleTimes.push_back(temp);
    }
    
    for(uint8_t ueIndex = 0; ueIndex < numOfUE; ++ueIndex)
    {
        std::cout << "UE " << ueIndex << " :" << std::endl;
        for(auto element : ueVecOfLcidToScheduleTimes[ueIndex])
        {
            std::cout << "  Logical Channel ID: " << element.first << ";count times: " << element.second << std::endl;
        }
    }
    */


    std::map<uint32_t, std::map<uint8_t, uint32_t>> mapOfUeToMapOfLcIdToCountTimes;
    std::map<uint8_t, uint32_t> temp;
    
    uint8_t startLcid = 3;
    for(uint8_t drbCount = 0; drbCount < numOfDrbPerUe; ++drbCount)
    {
        temp[startLcid++] = 0;
    }

    mapOfUeToMapOfLcIdToCountTimes[1234] = temp;
    mapOfUeToMapOfLcIdToCountTimes[2345] = temp;
    mapOfUeToMapOfLcIdToCountTimes[3456] = temp;

    auto iter = mapOfUeToMapOfLcIdToCountTimes.begin();
    std::cout << iter->first << std::endl;

    
    
    return 0;
}

