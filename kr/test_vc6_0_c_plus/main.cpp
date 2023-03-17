#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MySwap(int* p1, int* p2)
{
    // 无法交换
    /*int* pTmp = p1;
    p1 = p2;
    p2 = pTmp;*/
    // 必须要有间接访问才会有交换
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    // 地址传递大坑
    int a = 1;
    int b = 2;
    MySwap(&a, &b);
    printf("交换后a=%d, b=%d\n", a, b);
    return 0;
}