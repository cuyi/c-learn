#include <iostream>
using namespace std;

class Asingle{
private:
    Asingle() { cout << "Asingle construct" << endl;}
public:
    /* 
        Ҫ��ȡ����ģʽ����ô����ʵ�����������������static�ģ� 
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
