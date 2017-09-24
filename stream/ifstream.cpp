#include <iostream>

typedef struct{
    uint8_t age;
    uint8_t height;
    std::string country;
    std::string name;
}PersonAttribute;

void getValuesFromConfigFile(PersonAttribute &attribute)
{
    std::string line;
    std::ifstream ifs("./person_attribute.txt", std::fstream::in);

    while(ifs.good())
    {
        std::getline(ifs. line);
        std::cout << "person_attribute.txt:" << line.c_str() << std::endl;
        line.erase( std::remove_if( line.begin(), line.end(), ::isspace), line.end() );
    }
}