#include <iostream>
using namespace std;

// 参数位置为形参
int add(int a, int b)
{
    return a + b;
}

// void为函数无返回值
void swap(int num1, int num2)
{
    cout << "数据交换前: " << num1 << endl;
    cout << "数据交换前: " << num2 << endl;
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
    cout << "数据交换前: " << num1 << endl;
    cout << "数据交换前: " << num2 << endl;
    return;
}

// 可以通过函数的声明告诉编译器有函数存在,即可以不写函数体,将函数体定义在main函数的下面
// int max(int a, int b);

int main()
{
    // 传入的为实参,函数调用时会将实参传递给形参
    int sum = add(1, 2);
    cout << "加法结果为: " << sum << endl;

    // 值传递时，函数的形参发生改变，但不会影响实参
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << "数据a: " << a << endl;
    cout << "数据b: " << b << endl;
    // int max_value = max(a, b);
    return 0;
}

// int max(int a, int b)
// {
//     int max_value = a > b ? a : b;
//     cout << "最大值为: " << max_value << endl;
//     return max_value;
// }
