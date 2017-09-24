#include <iostream>
#include <list>

using namespace std;

struct MyMap{
    uint16_t lutos;
    uint16_t beauty;
};

class A{
public:
    A():m_val1(0), m_val2(0)
    {
        cout << "A constructor" << endl;
    }

    void addMyMapElement(const uint16_t& lutos, const uint16_t& beauty)
    {
        struct MyMap temp;
        temp.lutos = lutos;
        temp.beauty = beauty;
        myMapList.push_back(temp);
        myMapList.sort(cmp);
    }

    void printMyMapElement()
    {
        auto iter = myMapList.begin();
        while(iter != myMapList.end())
        {
            cout << "lutos: " << iter->lutos << " beauty: " << iter->beauty << endl;
            ++iter;
        }
    }
private:
    uint8_t m_val1;
    uint8_t m_val2;
    list<struct MyMap> myMapList;

static  bool cmp(const struct MyMap& first, const struct MyMap& second)
    {
        return (first.lutos > second.lutos);
    }
};



int main(void)
{
    A a;
    a.addMyMapElement(1, 4);
    a.addMyMapElement(2, 3);
    a.addMyMapElement(1, 5);

    a.printMyMapElement();

    return 0;
}
