#include <iostream>
using namespace std;

int main()
{
    // cout << "hello world" << endl;
    // 数组就是一个集合，里面存放了相同类型的数据元素,数组是由连续的内存位置组成的
    // 定义数组
    // int arr1[5];
    // arr1[0] = 1;
    // arr1[1] = 2;
    // arr1[2] = 3;
    // arr1[3] = 4;
    // arr1[4] = 5;
    // int arr2[5] = {1, 2, 3, 4, 5};
    // int arr3[] = {1, 2, 3, 4, 5};

    // // 20
    // cout << "数组长度为: " << sizeof(arr1) << endl;
    // cout << "数组长度为: " << sizeof(arr3) << endl;

    // cout << "数组中元素个数为: " << sizeof(arr3) / sizeof(arr3[0]) << endl;

    // // 数组首地址
    // cout << "数组首地址为: " << arr1 << endl;
    // cout << "数组中第一个元素的地址为: " << &arr1[0] << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "数组中数据的地址为: " << &arr3[i] << endl;
    // }

    // 小猪称体重
    // int arr[] = {3, 5, 1, 7, 9, 2, 100, 101, 200, 14, 201, 23, 45, 67, 12, 11};
    // int arr_len = sizeof(arr)/sizeof(arr[0]);
    // int max_value = 0;
    // for (int i=0; i<arr_len; i++)
    // {
    //     if (arr[i]>max_value)
    //     {
    //         max_value = arr[i];
    //     }
    // }
    // cout << "最重的猪为: " << max_value << endl;

    // 逆序数组
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr_len = sizeof(arr)/sizeof(arr[0]);
    // int tmp = 0;
    // for (int i=0; i<arr_len; i++)
    // {
    //     // 停止条件
    //     if (i<arr_len-i-1)
    //     {
    //         tmp = arr[i];
    //         arr[i] = arr[arr_len-i-1];
    //         arr[arr_len-i-1] = tmp;
    //     }
    // }

    // for (int i = 0; i < arr_len; i++)
    // {
    //     cout << "数据为: " << arr[i] << endl;
    // }

    // 冒泡排序
    int arr[] = {4, 2, 0, 8, 5, 7, 1, 3, 9};
    /*
        4, 2, 0, 8, 5, 7, 1, 3, 9
        2, 4, 0, 8, 5, 7, 1, 3, 9
        2, 0, 4, 8, 5, 7, 1, 3, 9
        2, 0, 4, 8, 5, 7, 1, 3, 9
        2, 0, 4, 5, 8, 7, 1, 3, 9
        2, 0, 4, 5, 7, 8, 1, 3, 9
        2, 0, 4, 5, 7, 1, 8, 3, 9
        2, 0, 4, 5, 7, 1, 3, 8, 9
        2, 0, 4, 5, 7, 1, 3, 8, 9

        0, 2, 4, 5, 7, 1, 3, 8
        0, 2, 4, 5, 7, 1, 3, 8
        0, 2, 4, 5, 7, 1, 3, 8
        0, 2, 4, 5, 7, 1, 3, 8
        0, 2, 4, 5, 1, 7, 3, 8
        0, 2, 4, 5, 1, 3, 7, 8
        0, 2, 4, 5, 1, 3, 7, 8
    */

    int len_arr = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < len_arr; i++)
    {
        for (int j = 0; j < len_arr - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
        // // break;
        // cout << "分割线-----" << endl;
        // for (int k = 0; k < len_arr; k++)
        // {
        //     cout << "数据为: " << arr[k] << endl;
        // }
    }

    return 0;
}