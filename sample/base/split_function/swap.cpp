#include "swap.h"

void swap(int a, int b)
{
    cout << "交换前a的值为: " << a << endl;
    cout << "交换前b的值为: " << b << endl;
    int tmp = a;
    a = b;
    b = tmp;
    cout << "交换后a的值为: " << a << endl;
    cout << "交换后b的值为: " << b << endl;
}

void swap_porint(int *a, int *b)
{
    cout << "交换前a的值为: " << *a << endl;
    cout << "交换前b的值为: " << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "交换后a的值为: " << *a << endl;
    cout << "交换后b的值为: " << *b << endl;
    return;
}