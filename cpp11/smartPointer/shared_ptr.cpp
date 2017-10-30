#include <memory>
#include <iostream>
#include <cassert>

/*
    shared_ptr : �и����ü����ĸ����¼���ж��ٸ�shared_ptrs��ָͬ��
                ͬһ������һ�����һ��������ָ�뱻���٣���������
                ���ü�������Ϊ0���������ᱻ�Զ�ɾ����
*/

void fun(std::shared_ptr<int> sp)
{
    std::cout << "fun: sp.use_count() = " << sp.use_count() << '\n';
}

class A 
{
    std::shared_ptr<int> no_;
public:
    A(std::shared_ptr<int> no) : no_(no) {}
    void value(int i) {
        *no_=i;
    }
};
class B 
{
    std::shared_ptr<int> no_;
public:
    B(std::shared_ptr<int> no) : no_(no) {}
    int value() const {
        return *no_;
    }
};

int main(void)
{
    auto sp1 = std::make_shared<int>(555);
    std::cout << "sp1.use_count() = " << sp1.use_count() << '\n';

    fun(sp1);

    std::cout << "sp1.use_count() = " << sp1.use_count() << '\n';


    // a and b share the same int.
    std::shared_ptr<int> temp(new int(390));
    A a(temp);
    B b(temp);
    a.value(28);
    assert(b.value() == 28);
    std::cout << "temp use_cout = " << temp.use_count() << std::endl;
    return 0;
    
}

