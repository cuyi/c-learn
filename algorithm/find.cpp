#include <iostream>
#include <algorithm>

int main(void)
{
    uint8_t drbSequence[300];
    for(int i = 0; i < 300; ++i)
        drbSequence[i] = (i + 3) % 255;

    uint16_t index = 0;
    uint8_t val = 45;
    std::find_if(drbSequence, drbSequence + sizeof(drbSequence), [&](uint8_t pp){if(!(pp == val)) ++index; return pp == val;});

    std::cout << index << std::endl;

    std::cout << std::rand() % index << std::endl;
    
    return 0;
}

