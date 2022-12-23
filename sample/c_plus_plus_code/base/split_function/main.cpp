#include <iostream>
using namespace std;
#include "swap.h"

int main()
{
    // 分文件
    // 创建.h后缀名的头文件
    // 创建.cpp后缀名的源文件
    // 在头文件中写函数的声明
    // 在源文件中写函数的定义
    // cout << "hello world" << endl;

    // 编译时需要将所有cpp文件都编译g++ main.cpp swap.cpp -o main
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << "a的值为: " << a << ", b的值为: " << b << endl;
    int x = 1;
    int y = 2;
    swap_porint(&x, &y);
    cout << "x的值为: " << x << ", y的值为: " << y << endl;
    return 0;
}