/*
 ��ģ���ػ������ں���ģ����ػ�������ģ�������ĳ���ض������µľ���ʵ�֡��������´��롣
 */

#include <iostream>
using namespace std;

template<typename T>class A{
    T num;
public:
    A(){
        num=T(6.6);
    }
    void print(){
        cout<<"A'num:"<<num<<endl;
    }
};

template<>class A<char*>{
    char* str;
public:
    A():str("hahaha\n"){}
    void print(){
        cout<<str<<endl;
    }
};

int main(){
    A<int> a1;      //��ʾģ��ʵ�ε���ʽʵ����
    a1.print();
    A<char*> a2;    //ʹ���ػ�����ģ��
    a2.print();
}