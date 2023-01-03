#include <iostream>
using namespace std;

int g_a = 1;
int g_b = 1;

const int c_g_a = 1;
const int c_g_b = 1;

int main()
{
    int a = 1;
    int b = 1;
    static int s_a = 1;
    static int s_b = 1;
    const int c_l_a = 1;
    const int c_l_b = 1;
    
    // 在全局区
    cout << "全局变量g_a的地址为: " << &g_a << endl;
    cout << "全局变量g_b的地址为: " << &g_b << endl;
    cout << "静态变量s_a的地址为: " << &s_a << endl;
    cout << "静态变量s_b的地址为: " << &s_b << endl;
    cout << "字符串的地址为: " << &"hello world" << endl;
    cout << "全局常量c_g_a的地址为: " << &c_g_a << endl;
    cout << "全局常量c_g_b的地址为: " << &c_g_b << endl;
    // 不在全局区
    cout << "局部变量a的地址为: " << &a << endl;
    cout << "局部变量b的地址为: " << &b << endl;
    cout << "局部常量c_l_a的地址为: " << &c_l_a << endl;
    cout << "局部常量c_l_b的地址为: " << &c_l_b << endl;
    return 0;
}