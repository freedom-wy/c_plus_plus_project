#include <iostream>
using namespace std;

// 指针的作用：可以通过指针间接访问内存

int main()
{
    int a = 10;
    // 创建指针
    int *p1;
    // 取变量的地址
    p1 = &a;
    cout << "a的地址为: " << &a << endl;
    cout << "p1的值为: " << p1 << endl;
    // 解引用*p 即为a地址所指向的变量数据
    *p1 = 1000; // 修改变量a的地址
    cout << "a的地址为: " << &a << endl;
    cout << "p1的值为: " << p1 << endl;
    cout << "a的数据为: " << a << endl;
    cout << "*p1解引用的数据为: " << *p1 << endl;

    // 指针占用的内存空间,32位操作系统占用4个字节, 64位操作系统占用8个字节, 与类型无关
    cout << "指针占用的内存空间为: " << sizeof(p1) << endl;
    cout << "指针占用的内存空间为: " << sizeof(int *) << endl;

    // 空指针和野指针
    // 空指针: 指针变量指向内存中编号为0的空间, 空指针用于初始化指针变量
    int *p2 = NULL;
    // 空指针是不能访问的
    // cout << "*p2的值为: " << *p2 << endl;

    // 常量指针, 指针的指向可以修改, 指针的值不能改
    int x = 10;
    int y = 20;
    // const int *p3 = &x;
    // cout << "p3的值为: " << p3 << endl;
    // p3 = &y;
    // cout << "p3的值为: " << p3 << endl;
    // cout << "*p3的值为: " << *p3 << endl;
    // *p3 = 20; // 不可修改

    // 指针常量 指针的指向不可以修改，指针的值可以修改
    // int *const p3 = &x;
    // cout << "p3的值为: " << p3 << endl;
    // *p3 = 20;
    // cout << "p3的值为: " << p3 << endl;
    // cout << "*p3的值为: " << *p3 << endl;
    // p3 = &y; // 不可修改

    // 指向和值都不能改
    const int *const p3 = &x;
    // p3 = &y; 不可修改
    // *p3 = 20; 不可修改

    int arr[] = {1, 2, 3, 4, 5};
    // 指针指向数组首地址
    int *p4 = arr;
    cout << "指针的地址大小为: " << sizeof(p4) << endl;
    // 通过解引用指针访问数组首个元素数据
    cout << "数组首个数据为: " << *p4 << endl;
    // 向后偏移4个字节
    p4++;
    cout << "数组首个数据为: " << *p4 << endl;

    int *p5 = arr;
    // 通过指针遍历数组
    for (int i=0; i<5; i++)
    {
        cout << "数组中数据为: " << *p5 << endl;
        p5++;
    }
    return 0;
}