#include <iostream>
using namespace std;

// struct Person
// {
//     string name;
//     int age;
// };

// struct Address
// {
//     struct Person p[10];
//     int size;
// };

int main()
{
    // struct Address address;
    // address.size = 0;
    // address.p[address.size].name = "张三";
    // address.p[address.size].age = 11;
    // address.size = address.size + 1;

    // address.p[address.size].name = "李四";
    // address.p[address.size].age = 22;
    // address.size = address.size + 1;

    // // address.p[1] = address.p[2];
    // // address.size = address.size-1;

    // for (int i = 0; i < address.size; i++)
    // {
    //     cout << "数据为: " << address.p[i].name << endl;
    // }

    // 引用
    int a = 10;
    int b = 20;

    // int &ref = a; // 引用必须初始化, 引用初始化后, 不可以改变
    // cout << "a的值为: " << a << endl;
    // cout << "ref的值为: " << ref << endl;
    // ref = 100;
    // cout << "a的值为: " << a << endl;
    // cout << "ref的值为: " << ref << endl;

    // int * const ref = &a;
    // ref = &b; // 指针常量不能修改指向
    // *ref = 100;
}