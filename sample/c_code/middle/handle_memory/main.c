#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
    char str1[64] = "hello world";
    memset(str1, 0, sizeof(str1)); // 将字符串全部填充为0
    printf("字符串数据为: %s\n", str1);
    printf("大小为: %d\n", sizeof(str1));
    printf("长度为: %d\n", strlen(str1));
    for(int i=0;i<sizeof(str1);i++)
    {
        printf("数据为: %c\n", str1[i]);
    }
}

void test2()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b[10];

    memcpy(b, a, sizeof(a)); // 将数组a拷贝给b, 通过内存拷贝
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        printf("数据为: %d\n", b[i]);
    }
}

void test3()
{
    int *p = NULL;
    p = malloc(sizeof(int));
    if (p == NULL)
    {
        printf("申请内存空间失败");
        return;
    }
    memset(p, 0, sizeof(int)); // 可以在使用内存前先清空内存
    *p = 100;
    printf("*p的值为: %d\n", *p);
    free(p); // 手动释放内存
}

void setArray(int* arr, int len)
{
    printf("传入的数据为: %d\n", arr);
    for(int i=0;i<len;i++)
    {
        // *(arr+i) = i;
        arr[i] = i;
    }
}

void test4()
{
    int arr[5];
    int* p1 = arr;
    int* p2 = &arr[0];
    printf("p1的值为: %d\n", p1);
    // printf("p2的值为: %d\n", p2);

    // for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    // {
    //     // printf("数组元素的值为: %d\n", p1[i]);
    //     printf("数组中元素的值为: %d\n", *(p1+i));
    // }
    setArray(p1, 5);
    
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        // printf("数组元素的值为: %d\n", p1[i]);
        printf("数组中元素的值为: %d\n", *(p1+i));
    }
}


int main()
{
    test4();
    return 0;
}