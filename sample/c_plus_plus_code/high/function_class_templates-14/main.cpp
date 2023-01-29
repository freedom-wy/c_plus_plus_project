#include <iostream>
using namespace std;

// 模板 交换数据
template<typename T> // 声明一个模板, 可以为typename 可以为class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void mySort(T arr[], int len)
{
    for(int i = 0;i<len;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                T tmp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = tmp;
            }
        }
    }
}

template<typename T>
void myPrint(T arr[], int len)
{
    for(int i=0;i<len;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int add1(int a, int b)
{
    return a + b;
}

template<class T>
T add2(T a, T b)
{
    return a + b;
}



void test1()
{
    // 使用注意事项：1、自动类型推导必须推导出一致的数据类型, 2、必须确定出T的数据类型, 才可以使用
    // 自动类型推导
    // int a = 10;
    // int b = 20;
    // cout << "a的值为: " << a << endl;
    // cout << "b的值为: " << b << endl;
    // mySwap(a, b);
    // 显示指定类型
    float c = 1.1;
    float d = 2.2;
    mySwap<float>(c, d);
    cout << "c的值为: " << c << endl;
    cout << "d的值为: " << d << endl;
}

void test2()
{
    // 冒泡排序 指定变量类型
    // int arr1[] = {4, 1, 6, 9, 0};
    // int len = sizeof(arr1)/sizeof(int);
    // mySort<int>(arr1, len);
    // myPrint<int>(arr1, len);
    // 自动推导
    char arr2[] = {"dabcfe"};
    int len = sizeof(arr2)/sizeof(char);
    mySort(arr2, len);
    myPrint(arr2, len);
}

void test3()
{
    // 隐式类型转换
    int a = 10;
    int b = 20;
    char c = 'a'; //a 97
    // cout << add1(a, c) << endl;
    // cout << add2(a, c) << endl; // 自动类型推导不能进行隐式类型转换
    cout << add2<int>(a, c) << endl; // 指定类型可以进行隐式类型转换
}

int main()
{
    test3();
    return 0;
}