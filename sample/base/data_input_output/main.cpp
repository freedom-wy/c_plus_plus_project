#include <iostream>
using namespace std;
#include <string>

// 定义常量
#define Day 7

int main(){
    // 变量
    // int a = 10;
    // cout << "a = " << a << endl;
    // 直接输出
    cout << "hello world" << endl;
    // 定义常量
    // 在文件的上方通过#define来进行定义宏常量或通过const来修饰变量,定义后不可修改
    // Day = 1; 不可修改
    cout << "一周总共有: " << Day << "天" << endl;
    const int month = 12;
    // month = 1; 不可修改
    cout << "一年总共有: " << month << "月" << endl;
    // 数据类型是变量在创建时给分配合理的内存空间,单位为字节
    // 通过sizeof来查看数据类型所占用的内存空间
    // cout << "short类型所占用的内存空间为: " << sizeof(short) << endl;
    // cout << "int类型所占用的内存空间为: " << sizeof(int) << endl;
    // cout << "long类型所占用的内存空间为: " << sizeof(long) << endl;
    // cout << "long long类型所占用的内存空间为: " << sizeof(long long) << endl;
    // float f1 = 3.1415926f;
    // 默认输出6位有效数字
    // cout << "圆周率为: " << f1 << endl;
    // 输出字符, 单引号中只有一个字符, 占1个字节
    // char ch = 'a';
    // cout << "字符为: " << ch << endl;
    // 字符串类型
    // string a = "hello world"; //主意需要#include <string>
    // char b[] = "hello world";
    // cout << "字符串为: " << a << endl;
    // cout << "字符串为: " << b << endl;
    // 布尔类型占用内存空间为1字节
    // 数据输入
    // int a = 0;
    // cout << "请给整形变量赋值: " << endl;
    // string a = "";
    // cout << "请给字符串赋值: " << endl;
    // cin >> a;
    // cout << "a的值为: " << a << endl;
    return 0;
}