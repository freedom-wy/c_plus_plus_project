#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // cout << "hello world" << endl;
    // int a2 = 10;
    // int b2 = 0;
    // while (b2<1000)
    // {
    //     b2 = ++a2 * 10;
    //     cout << "a2的值为: " << a2 << endl;
    //     cout << "b2的值为: " << b2 << endl;
    // }
    // int a = 0;
    // // 添加随机数种子
    // srand((unsigned int)time(NULL));
    // int b = rand() % 100 + 1; // 随机数
    // // cout << "随机数为: " << b << endl;
    // while (1)
    // {
    //     // int b = rand() % 100 + 1; // 随机数
    //     // cout << "b的值为: " << b << endl;
    //     cout << "请输入数字进行猜测: " << endl;
    //     cin >> a;
    //     if (a > b)
    //     {
    //         cout << "数字大了" << endl;
    //     }
    //     else if (a < b)
    //     {
    //         cout << "数字小了" << endl;
    //     }
    //     else if (a == b)
    //     {
    //         cout << "猜对了" << endl;
    //         break;
    //     }
    // }

    // int num = 100;
    // while (num < 999)
    // {
    //     // 取个位十位百位
    //     int a = num/100; // 百位
    //     int b = num/10%10; // 十位
    //     int c = num%10; // 个位
    //     if (a*a*a + b*b*b+ c*c*c == num)
    //     {
    //         cout << "水仙花数为: " << num << endl;
    //     }

    //     num++;
    // }

    for (int i = 1; i < 100; i++)
    {
        
        if (i % 7 == 0 || i%10==7 || i/10 == 7)
        {
                cout << "数字为: " << i << endl;
        }
    }

    return 0;
}