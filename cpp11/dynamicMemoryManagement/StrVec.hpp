#pragam once

#include <string>
#include <memory>

class StrVec{
public:
    StrVec():
      elements(nullptr), first_free(nullptr), cap(nullptr)
    {}

    StrVec(const StrVec);   // copy constructor
    StrVec& operator=(const StrVec&);   // overload assignment operator
    ~StrVec();  // destructor
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const (return first_free; )

private:
    static std::allocator<std::string> alloc; // allocate memeory
    void chk_n_alloc()
    {
        if (size() == capacity()
            reallocate();            
    }
    void free();
    void reallocate();
    
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


