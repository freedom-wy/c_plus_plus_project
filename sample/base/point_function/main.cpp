#include <iostream>
using namespace std;


void swap(int *p1, int *p2);

void swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    cout << "交换后的*p1和*p2的数据为: " << *p1 << *p2 << endl;
}

// void swap(int *p1, int len);

// void swap(int *p1, int len)
// {
//     for (int i=0; i<len; i++)
//     {
//         for (int j=0; j<len-i-1; j++)
//         {
//             if (p1[j] > p1[j+1])
//             {
//                 int tmp = p1[j];
//                 p1[j] = p1[j+1];
//                 p1[j+1] = tmp;
//             }
//         }
//     }
// }

int main()
{
    // 可以通过地址传递来修改实参的值
    int a = 1;
    int b = 2;
    swap(&a, &b);
    cout << "交换后的a和b的数据为: " << a << b << endl;

    // int arr[] = {5, 1, 3, 2};
    // 通过冒泡排序进行排序
    // 1, 5, 3, 2
    // 1, 3, 5, 2
    // 1, 3, 2, 5

    // 1, 3, 2
    // 1, 2, 3

    // 1, 2

    // swap(arr, 4);

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "数组数据为: " << arr[i] << endl;
    // }
    

    return 0;
}