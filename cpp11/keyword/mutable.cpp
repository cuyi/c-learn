/*
 *  g++ -std=c++14 filename.cpp
 *  g++ -std=c++17 filename.cpp
 *  
 *  ��C++�У�mutableҲ��Ϊ��ͻ��const�����ƶ����õġ�
 *  ��mutable���εı���������Զ���ڿɱ��״̬����ʹ��һ��const�����С�  
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <functional>

#include <set>
#include <string>
#include <memory>

class ClxTest
{
public:
    ClxTest();
    ~ClxTest();
    
    void Output() const;
    int GetOutputTimes() const;

private:
    mutable int m_iTimes;   // mutable make it possible to increase in const function
};

ClxTest::ClxTest():m_iTimes(0)
{}

ClxTest::~ClxTest()
{}

void ClxTest::Output() const
{
    std::cout << "Output for test!" << std::endl;

    // mutable make it possible to increase in const function
    // Or, it will print "error: increment of member ��ClxTest::m_iTimes�� in read-only object"
    m_iTimes++; 
}

int ClxTest::GetOutputTimes() const
{
    return m_iTimes;
}

void OutputTest(const ClxTest& lx)
{
    std::cout << lx.GetOutputTimes() << std::endl;
    lx.Output();
    std::cout << lx.GetOutputTimes() << std::endl;
}

int main(void)
{
    ClxTest obj1;
    OutputTest(obj1);
    
    return 0;
}

