#include <iostream>

enum Old{yes, no};
enum class New1{yes, no};
enum struct New2{yes, no};

inline const char* toString(const New1& newEnumType)
{
    switch(newEnumType)
    {
        case New1::yes:
            return "yes";
        case New1::no:
            return "no";
        default:
            break;
    }
    return "Error: unknow enum type";
}

inline std::ostream& operator<<(std::ostream& o, const New1& enumType)
{
    o << toString(enumType);
    return o;
}

int main(void)
{
    New1 e = New1::yes;
    std::cout << e << std::endl;

    return 0;
}

