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

void setValue(int* aa)
{
    aa = malloc(sizeof(int));
    memset(aa, 0, sizeof(int));
    *aa = 100;
}

void test2()
{
    int* a = NULL;
    setValue(a);
    printf("a的值为: %d\n", *a);
}

int main()
{
    test2();
    return 0;
}