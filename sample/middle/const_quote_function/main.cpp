#include <iostream>
using namespace std;


// 通过const来限定形参

void test1(const int &a)
{
    // 通过const修饰后, 不能修改
    // a = 100;
}

int test2(int a=1, int b=1);

int test2(int a, int b)
{
    return a+b;
}


int main()
{
    int a = 1;
    test1(a);
    cout << "a的值为: " << a << endl;

    int x = test2();
    cout << "x的值为: " << x << endl;
    return 0;
}