#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>

using namespace std;

int main(void)
{
    uint8_t val{0XFF};
    printf("%u\n", val);   
    uint8_t val1 = val + 1;

    uint8_t diff = (val1 >= val) ? (val1 - val) : (0xFF - val);
    printf("%u\n", val1 - val);   


    uint32_t val2{0XFFFFFFFF};
    printf("val2(%x)\n", val2);

    printf("numeric_limits<uint32_t>::max()(%x)\n", std::numeric_limits<uint32_t>::max());
    printf("numeric_linmits<int32_t>::max()(%x)\n", std::numeric_limits<int32_t>::max());
    printf("numeric_limits<uint32_t>::min()(%x)\n", std::numeric_limits<uint32_t>::min());
    printf("numeric_linmits<int32_t>::min()(%x)\n", std::numeric_limits<int32_t>::min());
    

    uint32_t o1 = 3;
    uint32_t o2 = 4;
    int32_t o3 = o1 -o2;
    int32_t o4 = static_cast<int32_t>(o1 - o2);

    printf("o3 %x, o4 %x\n", o3, o4);

    if(o3 > 0) 
        printf("o3 > 0 true\n");
    else 
        printf("o3 > 0 false\n");

    if(o4 > 0) 
        printf("o4 > 0 true\n");
    else
        printf("o4 > 0 false\n");

    int32_t o5 = o1 * (o1 - o2);

    if(o5 > 0)
        printf("o5 > 0 true\n");
    else
        printf("o5 > 0 false\n");

    vector<int> iv;
    std::cout << iv.capacity() << std::endl;

    iv.reserve(10);

    std::cout << iv.capacity() << std::endl;
    std::cout << iv.size() << std::endl;

    iv.push_back(88);
    std::cout << iv.size() << std::endl;

    cout << iv[0] << endl;

    return 0;
}
