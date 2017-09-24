#include<iostream>
#include<string>

enum CountryCode: uint16_t{
    CHINA       = 0,
    AMERICA     = 1,
    MALAYSIA    = 2    
};

class Singer{
public:
    virtual void printCountryCode() = 0;
    virtual void setCountryCode(const CountryCode countryCode) = 0;
};

class JokerXue: public Singer{
public:
    JokerXue() = default;
    void printCountryCode() { std::cout << countryCode_ << std::endl; }
    void setCountryCode(const CountryCode countryCode) { countryCode_ = countryCode;}

private:
    CountryCode countryCode_;
};

class FishLeong: public Singer{
public:
    FishLeong() = default;
    void printCountryCode() { std::cout << countryCode_ << std::endl; }
    void setCountryCode(const CountryCode countryCode) { countryCode_ = countryCode;}

private:
    CountryCode countryCode_;
};

class JackSon: public Singer{
public:
    JackSon() = default;
    void printCountryCode() { std::cout << countryCode_ << std::endl; }
    void setCountryCode(const CountryCode countryCode) { countryCode_ = countryCode;}

private:
    CountryCode countryCode_;
};

/*
    pass a pointer point to a child class can automatically 
    call the child's printCountryCode() because of 
    virtual based polymorphism
*/
void callPrintCountryCode(Singer *p)    
{
    p->printCountryCode();
}

int main(void)
{
    Singer* pSinger = new JokerXue;
    pSinger->setCountryCode(CountryCode::CHINA);
    callPrintCountryCode(pSinger);
    pSinger = new FishLeong;
    pSinger->setCountryCode(CountryCode::MALAYSIA);
    callPrintCountryCode(pSinger);
    pSinger = new JackSon;
    pSinger->setCountryCode(CountryCode::AMERICA);
    callPrintCountryCode(pSinger);
    

    return 0;
}
