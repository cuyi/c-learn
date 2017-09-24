/*
 *  g++ -std=c++14 filename.cpp
 *  g++ -std=c++17 filename.cpp
 *  
 *  std::make_unique<T>()   // c++ 14
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <functional>

#include <set>
#include <string>
#include <memory>

class CString
{
    char* _str;

public:
    //构造函数
    //CString () {}
    CString () = default;
    CString(const char* pstr) : _str(nullptr)
    {
        UpdateString(pstr);
    }

    //析构函数
    ~CString()
    {
        if (_str)
            free(_str);
    }

public:
    void UpdateString(const char* pstr) throw()
    {
        if (pstr == nullptr)
            return;

        if (_str)
            free(_str);

        _str = (char*)malloc(strlen(pstr) + 1);
        strcpy(_str,pstr);
    }

public:
    char* GetStr() const throw()
    {
        return _str;
    }
};


template<typename T>
class CStackMemoryAlloctor
{
    mutable T* _ptr;

public:
    explicit CStackMemoryAlloctor(size_t size) throw() : _ptr(nullptr)
    {
        _ptr = (T*)malloc(size);
    }

    ~CStackMemoryAlloctor()
    {
        if (_ptr)
            free(_ptr);
    }

public:
    operator T*() const throw()
    {
        T* tmp = _ptr;
        _ptr = nullptr;
        return tmp;
    }

public:
    T* GetPtr() const throw()
    {
        return _ptr;
    }

//private:
//    void* operator new(std::size_t)
//    {
//        return nullptr;
//    }

public:
    void* operator new(std::size_t) = delete;   // force not to use new operator
};

int main(int argc, char *argv[])
{
    //auto ptr = std::make_unique<CString>("123ABC");     
    auto ptr = std::make_unique<CString>();
    
    printf(ptr->GetStr() == nullptr ? "None\n" : ptr->GetStr());
    ptr->UpdateString("Hello xixi\n");
    printf(ptr->GetStr() == nullptr ? "None\n" : ptr->GetStr());

    CStackMemoryAlloctor<char> str(128);  
    char* pstr = str.GetPtr();
    strcpy(pstr, "what?\n");

    auto p = std::make_unique<CStackMemoryAlloctor<char>>(128); // error , because of make_unique will use "new", however the new operator is overloaded as "delete"
    char* pstr1 =p->GetPtr();
    strcpy(pstr1, "how?\n");
    
    printf(pstr1); 

    
    return 0;
}

