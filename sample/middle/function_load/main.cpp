#include <iostream>
using namespace std;

void test1()
{
    cout << "重载1" << endl;
}

void test1(int a)
{
    cout << "重载2" << endl;
}

void test1(float a, int b)
{
    cout << "重载3" << endl;
}

// 报错, 不能重载不同类型的函数
// int test1()
// {
//     cout << "重载3" << endl;
// }

int main()
{
    test1(3.14, 1);
    return 0;
}