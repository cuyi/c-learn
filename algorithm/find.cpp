#include <iostream>
#include <algorithm>
#include <array>
#include <utility>

std::array<std::pair<const uint32_t, const uint32_t>, 12>  arr{{{0, 1},
                                                              {2, 10},
                                                              {11, 20},
                                                              {21, 50},
                                                              {51, 100},
                                                              {101, 500},
                                                              {501, 1000},
                                                              {1001, 2000},
                                                              {2001, 3000},
                                                              {3001, 4000},
                                                              {4001, 5000},
                                                              {5001, 0xFFFFFFFF}}};



int main(void)
{
    /*
    uint8_t drbSequence[300];
    for(int i = 0; i < 300; ++i)
        drbSequence[i] = (i + 3) % 255;

    uint16_t index = 0;
    uint8_t val = 45;
    std::find_if(drbSequence, drbSequence + sizeof(drbSequence), [&](uint8_t pp){if(!(pp == val)) ++index; return pp == val;});

    std::cout << index << std::endl;

    std::cout << std::rand() % index << std::endl;
    */

    uint16_t index = 0;
    uint8_t val = 45;
    bool flag{false};
    std::find_if(arr.begin(), arr.end(), [&](std::pair<const uint32_t, const uint32_t> element){
            if(element.first <= val and val <= element.second)
            {
                flag = true;
                return flag;
            }
            else
            {
                ++index;
                return flag;
            }
        });
    std::cout << "index = " << index << std::endl;

    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;
    return 0;
}

