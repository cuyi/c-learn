#include <iostream>
#include <forward_list>

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

    void addMyMapElementThenSort(const uint16_t& lutos, const uint16_t& beauty)
    {
        struct MyMap temp;
        temp.lutos = lutos;
        temp.beauty = beauty;
        
        myMapList.push_front(temp);
        myMapList.sort(cmp);
    }

    void insertMyMapElementKeepItOrdered(const uint16_t& lutos, const uint16_t& beauty)
    {
        struct MyMap temp;
        temp.lutos = lutos;
        temp.beauty = beauty;

        if(!myMapList.empty())
        {
            auto slowIter = myMapList.before_begin();
            auto fastIter = myMapList.begin();
            for(; fastIter!= myMapList.end(); ++slowIter, ++fastIter)
            {
                if(fastIter!= myMapList.end() && temp.lutos >= fastIter->lutos)
                {
                    myMapList.insert_after(slowIter, temp);
                    break;
                }
                else if(fastIter== myMapList.end())
                    myMapList.insert_after(slowIter, temp);
            }
        }
        else
            myMapList.push_front(temp);

        
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
    forward_list<struct MyMap> myMapList;

static  bool cmp(const struct MyMap& first, const struct MyMap& second)
    {
        return (first.lutos > second.lutos);
    }
};



int main(void)
{
    A a;
    /*
    a.addMyMapElementThenSort(1, 4);
    a.addMyMapElementThenSort(2, 3);
    a.addMyMapElementThenSort(1, 5);
    */
    a.insertMyMapElementKeepItOrdered(1, 4);
    a.insertMyMapElementKeepItOrdered(2, 3);
    a.insertMyMapElementKeepItOrdered(1, 5);

    a.printMyMapElement();

    return 0;
}

