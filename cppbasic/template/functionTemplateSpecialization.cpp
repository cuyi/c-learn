/*
 *
 ʹ����ͨ�������غ�ʹ��ģ���ػ������в�֮ͬ������Ҫ�����������������棺 
��1�����ʹ����ͨ���غ�������ô�����Ƿ���ʵ�ʵĺ������ã�������Ŀ���ļ������ɸú����Ķ����ƴ��롣
    �����ʹ��ģ����ػ��汾�����Ƿ����������ã����򲻻���Ŀ���ļ��а����ػ�ģ�庯���Ķ����ƴ��롣����Ϻ���ģ��ġ�����ʵ������׼��
��2�����ʹ����ͨ���غ�������ô�ڷ������ģʽ�£�Ӧ���ڸ���Դ�ļ��а������غ�����������������ĳЩԴ�ļ��оͻ�ʹ��ģ�庯�������������غ�����
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

template<typename T> T Max(T t1,T t2){
    return (t1>t2)?t1:t2;
}

typedef const char* CCP;
// ����ģ���ػ��Ķ���
template<> 
CCP Max<CCP>(CCP s1,CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

// ���˶��庯��ģ���ػ��汾�⣬������ֱ�Ӹ���ģ�庯�����ض������µ�������ʽ����ͨ������
CCP Max(CCP s1, CCP s2){
    return (strcmp(s1,s2)>0)?s1:s2;
}

int main(){
    //����ʵ����int Max<int>(int,int)
    int i=Max(10,5);
    //������ʾ�ػ���const char* Max<const char*>(const char*,const char*)
    const char* p=Max<const char*>("very","good");
    cout<<"i:"<<i<<endl;
    cout<<"p:"<<p<<endl;
}

