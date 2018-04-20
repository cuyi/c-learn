#include <iostream>

class A
{
public:
	A(){std::cout<<"A constructor."<<std::endl;}
	virtual ~A(){std::cout<<"A destructor."<<std::endl;}
	void print(){std::cout<<"A print."<<std::endl;}
};

class B : virtual public A
{
public:
	B(){std::cout<<"B constructor."<<std::endl;}
	~B(){std::cout<<"B destructor."<<std::endl;}
	//virtual void print(){std::cout<<"B print."<<std::endl;}
};

class C : virtual public A
{
public:
	C(){std::cout<<"C constructor."<<std::endl;}
	virtual ~C(){std::cout<<"C destructor."<<std::endl;}
	//virtual void print(){std::cout<<"C print."<<std::endl;}
};

class D : public B, public C
{
public:
	D(){std::cout<<"D constructor."<<std::endl;}
	~D(){std::cout<<"D destructor."<<std::endl;}
};

int main()
{
	D* dp = new D;
	
	dp->print();
	
	delete dp;
}
