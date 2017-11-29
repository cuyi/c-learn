// 告诉编译器按照C的规则编译，不然dlsym 的时候找不到对应的符号
extern "C"{

int add(int a,int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int div(int a, int b)
{
    return (a / b);
}

}