#include<iostream>
using namespace std;

int main()
{
    // cout << "hello world" << endl;
    // 二维数组
    // int arr[2][3]; // 定义2行3列数组
    // arr[0][0] = 1;
    // arr[0][1] = 2;
    // arr[0][2] = 3;
    // arr[1][0] = 4;
    // arr[1][1] = 5;
    // arr[1][2] = 6;

    // 优选第二种定义方式
    int arr[2][3] = {
        {1, 2, 3}, 
        {4, 5, 6}
        };

    // int arr[2][3] = {1, 2, 3, 4, 5, 6};
    // int arr[][3] = {1, 2, 3, 4, 5, 6};
    // 外层打印行,内层打印列
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "数据为: " << arr[i][j] << endl;
    //     }
        
    // }

    cout << "二维数组占用空间大小为: " << sizeof(arr) << endl;
    cout << "二维数组第一行数据占用空间大小为: " << sizeof(arr[0]) << endl;
    cout << "二维数组第一行第一个数据数据占用空间大小为: " << sizeof(arr[0][0]) << endl;
    // 总空间大小除以1行所占用空间即为行数
    // 一行空间除以一个数据占用空间即为列数
    return 0;
}