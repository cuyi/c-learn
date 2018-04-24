#include <iostream>
#include <memory>

/*
    weak_ptr : ��Ϊ���shared_ptr�������һ������
        ָ����Э��shared_ptr�����������Դ�һ��shared_ptr��
        ��һ��weak_ptr�����죬���Ĺ��������������������
        ���������ӻ���١�û������*��->������ʹ��lock���
        һ�����õ�shared_ptr����.
*/
void observe(std::weak_ptr<int> weak) 
{
    std::cout << "\tweak use_count = " << weak.use_count() << '\n';
    if (auto observe = weak.lock()) {
        std::cout << "\tobserve() able to lock weak_ptr<>, value=" << *observe << "\n";
        std::cout << "\tweak use_count = " << weak.use_count() << '\n';
        std::cout << "\tobserve use_count = " << observe.use_count() << '\n';
    } else {
        std::cout << "\tobserve() unable to lock weak_ptr<>\n";
    }
    std::cout << "\tweak use_count = " << weak.use_count() << '\n';
}

int main(void)
{
    std::weak_ptr<int> weak;
    std::cout << "weak_ptr<> not yet initialized\n";
    observe(weak);

    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "\tshared use_count = " << shared.use_count() << '\n';
        std::cout << "weak_ptr<> initialized with shared_ptr.\n";
        observe(weak);
    }

    std::cout << "shared_ptr<> has been destructed due to scope exit.\n";
    observe(weak);

    return 0;
}
