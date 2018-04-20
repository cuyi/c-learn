#include <iostream>
#include <cstdint>

typedef struct RlcDlSdu_t{
private:
	uint8_t*    data;
	uint32_t    size    	: 13;

public:
    uint32_t    cause   	: 3;
	uint32_t    packetId;

	struct RlcDlSdu_t*    next;
	struct RlcDlSdu_t*    prev;

	uint32_t    sn;
	uint32_t    retx_count;

}RlcDlSdu_t;


int main(void)
{
    std::cout << "sizeof(RlcDlSdu_t) = " << sizeof(RlcDlSdu_t) << std::endl;
     return 0;
}

