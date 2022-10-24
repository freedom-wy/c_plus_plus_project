#include <iostream>
using namespace std;

int *func()
{
    // 栈区的形参和局部变量不要返回
    // int a = 10;
    // return &a;

    // new一个在堆区的数据, 可以返回地址供外部程序使用
    int *p = new int(10);
    return p;
}

void test1()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    delete p;
    cout << *p << endl;
}

void test2()
{
    // int a[5] = {1, 2, 3, 4, 5};
    int a[5];
    int *p = a;
    for (int i = 0; i < 5; i++)
    {
        // cout << "数据为: " << *p << ", 地址为: " << p << endl;
        *p = i;
        p++;
    }

    p = a;

    for (int i = 0; i < 5; i++)
    {
        cout << "数据为: " << *p << ", 地址为: " << p << endl;
        p++;
    }
}

void test3()
{
    // int *p1 = new int[5];
    // cout << p1[0] << endl;
    // cout << p1[1] << endl;
    // cout << p1[2] << endl;
    // cout << p1[3] << endl;
    // cout << p1[4] << endl;

    int a[5] = {1, 2, 3, 4, 5};
    int *p2 = a;
    cout << p2 << endl;
    cout << p2[0] << endl;
    // cout << p2[0] << endl;
    // cout << p2[1] << endl;
    // cout << p2[2] << endl;
    // cout << p2[3] << endl;
    // cout << p2[4] << endl;

}

// 堆区和栈区

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}