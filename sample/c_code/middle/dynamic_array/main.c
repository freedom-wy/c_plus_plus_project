#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void setArray(int* arr, int len)
{
    printf("请输入数组中数据\n");
    for(int i=0;i<len;i++)
    {
        scanf("%d", arr+i);
    }
}

void printArray(int* arr, int len)
{
    for(int i=0;i<len;i++)
    {
        printf("数组中数据为: %d\n", *(arr+i));
    }
}

void test1()
{
    int num = 0;
    printf("请输入数组元素个数\n");
    scanf("%d", &num);

    // 在堆区申请内存
    int* arr = malloc(sizeof(int)*num);
    if(arr == NULL)
    {
        printf("申请失败\n");
        return;
    }

    // 清空内存
    memset(arr, 0, sizeof(int)*num);

    // 设置数组数值
    setArray(arr, num);
    // 查看数据
    printArray(arr, num);
    
    // 释放内存
    free(arr);
}

void setValue(int** aa)
{
    printf("aa的值为: %p\n", aa);
    printf("*aa的地址为: %p\n", *aa);
    // 地址传递, 由于实参是指针地址, 因此形参需要用二级指针接收
    *aa = malloc(sizeof(int)); // 需解引用到一级指针, int* a = malloc(sizeof(int));
    memset(*aa, 0, sizeof(int));
}

// int* returnLocalPoint()
// {
//     int a = 10;
//     int* p;
//     p = &a;
//     return p;
// }

// int* returnMallocPoint()
// {
//     int* p = malloc(sizeof(int));
//     // *p = 100;
//     return p;
// }

void test2()
{
    int num = 10;
    int* a = &num;
    // printf("NULL的地址为: %p\n", &NULL); // 不能取NULL的地址
    printf("num的地址为: %p\n", &num);
    printf("a的地址为: %p\n", &a);
    // 传入指针地址
    setValue(&a);
    *a = 1000;
    printf("a的值为: %d\n", *a);
    free(a);
    // int* a = returnMallocPoint();
}

void test3()
{
    // 二级指针
    int a = 10;
    int* p = &a;
    printf("a的地址为: %p\n", p);
    printf("p的值为: %p\n", &a);
    // 二级指针
    int** pp = &p; //*pp解引用的值为p的值, 即为&a; **pp解引用即为a的值, 为10.
    printf("&p的值为: %p\n", &p);
    printf("pp的地址为: %p\n", pp);
}

int main()
{
    test2();
    return 0;
}