#include <iostream>
#include <memory>

/*
    weak_ptr : 是为配合shared_ptr而引入的一种智能
        指针来协助shared_ptr工作，它可以从一个shared_ptr或
        另一个weak_ptr对象构造，它的构造和析构不会引起引用
        记数的增加或减少。没有重载*和->但可以使用lock获得
        一个可用的shared_ptr对象.
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
