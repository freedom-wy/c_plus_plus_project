#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testAdd(int a, int b)
{
    return a+b;
}

// 通过typedef定义新的类型
typedef int(*PFNTESTADD)(int, int);

int main()
{
    PFNTESTADD pfntestAdd = NULL;
    //int(*p)(int, int)=NULL; // 定义一个函数指针
    pfntestAdd = testAdd; // 指针变量赋值
    int c = (*pfntestAdd)(1, 2); // 指针函数调用和传参
    printf("c=%d\n", c);
    return 0;
}