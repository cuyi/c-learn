#include <iostream>

class D{
public:
    D(int a);
    D(const D& dobj);

    int m_b[10000];
};

D::D(int a){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = a;
    }
}


D::D(const D& dobj){
    for(int i = 0; i < 10000; ++i){
        m_b[i] = dobj.m_b[i];
    }
}


D merge(D dobj1, D dobj2){
    D retVal(0);
    for(int i = 0; i < 10000; ++i){
        retVal.m_b[i] = dobj1.m_b[i] + dobj2.m_b[i];
    }

    return retVal;
}
int main(void)
{
    D dobj(1);
    D dobj2(3);
    for(int i = 0; i < 1; ++i)
        merge(dobj, dobj2);
    
    return 0;
}

