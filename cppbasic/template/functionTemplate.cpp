/*
 * �Ժ���ģ���ʹ�ö��ԣ���Ϊ���ֵ��÷�ʽ��
 * һ������ʾģ��ʵ�ε��ã���ʾ���ã���
 * һ������ʽģ��ʵ�ε��ã���ʽ���ã���
 * ������ģ���ʹ�ö��ԣ�û����ʽģ��ʵ�κ���ʽģ��ʵ��ʹ�õ�˵������Ϊ��ģ���ʹ�ñ�����ʾָ��ģ��ʵ��
 */

#include <iostream>

template<typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
    if(f(v1, v2)) return -1;    // v1 < v2 , -1
    if(f(v2, v1)) return 1;     // v1 > v2 , 1
    return 0;                   // v1 = v2 , 0
}

/* 
 *  �����Ƿ����������ã�������ͨ����ʾʵ���� ���� ������ģ��ʵ���� 
 *  template int compare<int>(const int &v1, const int &v2, std::less<int> f);
 */

// This a funciont template explicit function definition  ����ģ����ʽ�ػ�
// default argument specified in explicit specialization is not allowed
template<> int compare<int>(const int &v1, const int &v2, std::less<int> f)
{
    if(f(v1, v2)) return -1;    // v1 < v2 , -1
    if(f(v2, v1)) return 1;     // v1 > v2 , 1
    return 0;                   // v1 = v2 , 0
}

template <typename T>
void func(T t)
{
    std::cout << t << std::endl;
}

void invoke(void (*p)(int))
{
    int num = 10;
    p(num);
}


/*
 * ����չʾ��ʽģ��ʵ�����ı�Ҫ��
 */
template <typename T> T Max(const T& t1, const T& t2)
{
    return (t1  >t2) ? t1 : t2;
}

int main(void)
{
    int ret = compare<int>(1, 2);   // ����ģ����ʾʵ����
    // int ret = compare(1, 2);     // ����ģ����ʽʵ����

    std::cout << ret << std::endl;

    invoke(func);                   // ����ģ����ʽʵ����
    invoke(func<int>);              // ����ģ����ʾʵ����

    int i=5;
    //std::cout << Max(i,'a') << std::endl; //�޷�ͨ������ : error: no matching function for call to Max(int&, char)
    std::cout << Max<int>(i,'a') << std::endl; //��ʾ���ã�ͨ������

    return 0;
}
