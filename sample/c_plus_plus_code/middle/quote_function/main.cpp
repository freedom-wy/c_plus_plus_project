// 通过引用, 形参可以影响实参
#include <iostream>
using namespace std;

// 值传递
void swap1(int a, int b);
// 地址传递
void swap2(int *a, int *b);
// 引用传递
void swap3(int &a, int *b);

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "值传递子函数a:" << a << endl;
    cout << "值传递子函数b:" << b << endl;
}

void swap2(int *a, int *b)
{
    cout << "参数*a: " << *a << endl;
    cout << "参数a: " << a << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "地址传递子函数a:" << *a << endl;
    cout << "地址传递子函数b:" << *b << endl;
}

void swap3(int &a, int &b)
{
    // 参数中&a为变量a的引用, 同名引用
    cout << "参数&a: " << &a << endl;
    cout << "参数a: " << a << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "引用传递子函数a:" << a << endl;
    cout << "引用传递子函数b:" << b << endl;
}



int main()
{
    int a = 1;
    int b = 2;
    swap3(a, b);
    // swap2(&a, &b);
    // swap1(a, b);
    cout << "传递后a: " << a << endl;
    cout << "传递后b: " << b << endl;

}