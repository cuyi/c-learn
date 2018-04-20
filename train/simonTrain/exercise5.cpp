#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

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

D merge1(D& dobj1, D& dobj2){
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

    std::cout << "Pass value:\n";
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 500000; ++i)
        merge(dobj, dobj2);

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";

    ////////////////////////////////////////////////////////
    D dobj3(1);
    D dobj4(3);

    std::cout << "Pass reference:";
    std::clock_t c_start3 = std::clock();
    auto t_start3 = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 500000; ++i)
        merge1(dobj3, dobj4);

    std::clock_t c_end3 = std::clock();
    auto t_end3 = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end3-c_start3) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end3-t_start3).count()
              << " ms\n"; 

    return 0;
}


