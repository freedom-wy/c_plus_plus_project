#include <iostream>
using namespace std;

int main()
{
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