#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

class Book{
public:
    Book() = default;
    Book(string name, uint16_t price):bookPrice(price), bookName(name){}

    Book(const Book& otherBook)
    {
        bookName = otherBook.bookName;
        bookPrice = otherBook.bookPrice;
    }
    ~Book(){};

    

    uint16_t getBookPrice() const { return bookPrice; }
    string getBookName() const { return bookName; }

    void setBookPrice(uint16_t price) { bookPrice = price; }
    void setBookName(string name) { bookName = name; }
private:
    uint16_t bookPrice;
    string bookName;
};

/* 
    �����������������Ƿǳ�Ա����
    Ϊ����������������һ�£� operator<< һ��Ҫ��������ostream �β�
 */
ostream& operator<<(ostream& os, const Book book)
{
    os << book.getBookName() << " " << book.getBookPrice();
    return os;
}

istream& operator>>(istream& is, Book& book)
{
    string temp;
    uint16_t val;
    
    is >> temp >> val;
    
    if(is)
    {
        book.setBookName(temp);
        book.setBookPrice(val);
    }
    else
    {
        book = Book("NONAME", 0);
    }

    return is;
}

int main(void)
{
    Book bookObj("C++", 100);
    cout << bookObj << endl;

    Book b;
    cin >> b;
    cout << b << endl;
    return 0;
}
