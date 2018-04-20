#include <iostream>
using namespace std;

class Asingle{
private:
    Asingle() { cout << "Asingle construct" << endl;}
public:
    /* 
        要获取单例模式，那么创建实例的这个函数必须是static的， 
    */
    static Asingle* createInstance()
    {
        if(pInstance == NULL){
            Asingle* temp = new Asingle;
            pInstance = temp;
        }
        return pInstance;
        
    }
private:
    static Asingle* pInstance;
};

Asingle* Asingle::pInstance = NULL;

int main(void)
{
    Asingle* p = Asingle::createInstance();
    return 0;
}
