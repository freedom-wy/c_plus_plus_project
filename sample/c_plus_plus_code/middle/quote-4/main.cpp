#include <iostream>
using namespace std;


// 引用 实质是能改值不能改指向

int main()
{
    // 引用的实质是指针常量
    // int a = 10;
    // int* const p1 = &a;
    // int b = 20;
    // // p1 = &b;
    // *p1 = 20;
    // cout << "a的值为: " << a << endl;
    int a = 10;
    int &b = a;
    b = 100;
    // int c = 20;
    // int &b = c; // 报错
    cout << "a的数据为: " <<  a << endl;
    cout << "b的数据为: " <<  b << endl;
    // cout << "b的数据为: " <<  c << endl;
    return 0;
}