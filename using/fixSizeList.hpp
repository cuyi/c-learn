#include <iostream>
#include <cstdint>

template<typename T, uint32_t MAX_SIZE>
class FixSizeList{
public:
    FixSizeList(): cur_count_(0) {}

    uint32_t getCurCount() const { return cur_count_; }
    T* getElements() { return elements_; }

    bool isFull() { return MAX_SIZE == getCurCount(); }
    bool find(const T& element)
    {
        for(uint32_t index = 0; index < getCurCount(); ++index)
        {
            if(elements_[index] == element)
            {
                return true;
            }
        }
        return false;
    }
    bool pushBack(const T& element)
    {
        if(!isFull()){
            elements_[cur_count_] = element;
            cur_count_++;
            return true;
        }
        return false;
    }
    void clear(){ cur_count_ = 0; }
private:
    uint32_t cur_count_;
    T elements_[MAX_SIZE];
};

template<typename T, uint32_t MAX_SIZE>
class FixSizeListWithUniqueElement: 
    private FixSizeList<T, MAX_SIZE>
{
public:
    typedef FixSizeList<T, MAX_SIZE> base;

    using base::clear;
    using base::getElements;

    bool add(const T& element){
        return base::find(element) || base::pushBack(element);
    }
protected:
    using base::find;
    using base::pushBack;

};