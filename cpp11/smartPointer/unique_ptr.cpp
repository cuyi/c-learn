#include <memory>
#include <iostream>

/*
    unique_ptr:���жԶ���Ķ���Ȩ:
        1. ����unique_ptr ������ָ��ͬһ������
        2. ���ܽ��и��Ʋ���ֻ�ܽ����ƶ�����
    unique_ptrָ��Ķ���ᱻ�Զ��ݻ�:
        1. ��ָ��Ķ����ƻ�
        2. ����ͨ�� operator=() ���� reset() ��ָ������һ��ָ��
*/

int main(void)
{
    std::unique_ptr<int> p1(new int(2));
    *p1 = 5;
    std::cout << "*p1 = " << *p1 << '\n';
    
    //std::unique_ptr<int> p2 = p1; error

    // ת������Ȩ�������ǿ��ڴ�� p2 ���У�p1��Ϊ��Чָ��
    std::unique_ptr<int> p2 = std::move(p1); 
    std::cout << "*p2 = " << *p2 << '\n';

    // after move, p1 is not a valid pointer, the follwing 
    // operation will cause segmentation fault
    // std::cout << "*p1 = " << *p1 << '\n'; 
    if(p1 == nullptr)
        std::cout << "p1 is nullptr now" << std::endl;
    else
        std::cout << "p1 is not valid pointer, either not a nullptr" << '\n';


    return 0;
}
