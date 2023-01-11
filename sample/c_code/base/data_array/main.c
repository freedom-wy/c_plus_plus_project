#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 100 // 定义常量时不写后面的分号


void test1()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("数组指针为: %p\n", a);
    printf("数组中第一个元素的指针为: %p\n", &a[0]);

    for(int i=0;i<sizeof(a)/sizeof(a[0]); i++)
    {
        printf("数组中元素值为: %d\n", a[i]);
    }
}

void test2()
{
    // char buf1[] = {'h', 'e', 'l', 'l', 'o'}; // 无结束标志符, char类型数组
    // printf("字符串为: %s\n", buf1);
    char buf2[12] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    // printf("字符串地址: %p\n", buf2);
    // printf("字符串占用空间大小: %d\n", sizeof(buf2));
    printf("字符串长度: %lu\n", strlen(buf2)); // 不包含\0
    // printf("字符串为: %s\n", buf2);
    // char buf3[] = "hello world"; //字符串初始化, 双引号, 编译器自动在后面补0, 推荐写法
    // printf("字符串为: %s\n", buf3);
}

void test3()
{
    char buf3[14];
    fgets(buf3, sizeof(buf3), stdin); // 可以接收空格, 会检测数组越界情况, 越界丢弃
    printf("%s\n", buf3);
}

void test4()
{
    char buf4[14] = "hello world";
    puts(buf4); // 自动添加换行
    fputs(buf4, stdout); // 不会自动添加换行
}

void test5()
{
    printf("时间戳为: %ld\n", time(NULL));
}

// void test6()
// {
//     printf("char *所占用空间大小: %d\n", sizeof(char *));
//     printf("short *所占用空间大小: %d\n", sizeof(short *));
//     printf("long *所占用空间大小: %d\n", sizeof(long *));
//     printf("int *所占用空间大小: %d\n", sizeof(int *));
// }

 void test7()
 {
    void * p = NULL;
    int num = 10;
    p = &num;
    // 输出数据前需强转为int *, 否则无法解引用
    printf("输出指针中保存的数据: %d\n", *(int*)p);
 }

 void test8()
 {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("a的地址为: %p\n", a);
    printf("a的数据为: %d\n", *a);
    // for (int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
    // {
    //     // printf("数据为: %d\n", a[i]);
    //     printf("%p\n", *(a+i));
    // }
 }

 void test9()
 {
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    int num5 = 50;

    int *arr[5] = {&num1, &num2, &num3, &num4, &num5};

    for(int i=0; i<sizeof(arr)/sizeof(int*); i++)
    {
        printf("数据为: %d\n", *arr[i]);
    }

 }

 void test10()
 {
    int a = 10;
    unsigned int b = 20;
    printf("有符号整形占用空间大小为: %d\n", sizeof(a));
    printf("无符号整形占用空间大小为: %d\n", sizeof(b));
 }

// c语言不支持函数的默认参数
//  void test11(int a=10, int b=20)
//  {
//     printf("a的值为: %d", a);
//  }



void test11(int *arr, int arr_len)
{
    printf("数组大小为: %d\n", sizeof(arr));
    for(int i = 0; i < arr_len; i++)
    {
        printf("数组中元素的值为: %d\n", arr[i]);
        // arr++;
    }
}

void test12(int arr[], int arr_len)
{
    printf("数组大小为: %d\n", sizeof(arr));
    for(int i = 0; i < arr_len; i++)
    {
        printf("数组中的元素值为: %d\n", arr[i]);
    }
}

void test13()
{ 
    // char str1[5] = {'h', 'e', 'l', 'l', 'o'}; // 不是字符串, 是字符数组, 无论数组是否限定长度, 都不会在后面添加\0
    // printf("str1的值为: %s\n", str1); // 因为str后面没有\0结束符, 因此输出hello后会输出乱码
    // char str2[10] = {'h', 'e', 'l', 'l', 'o'}; // 字符数组, 是字符串, 后面会通过\0补齐
    // printf("str2的值为: %s\n", str2);
    // char str3[2] = "hello world"; // 自动添加\0
    char str3[2] = "hello world"; // 自动添加\0, 如果越界, 会舍弃\0, 造成乱码
    printf("str3的值为: %s\n", str3);

    char* str4 = "hello world"; // 字符常量, 不能修改
    char str5[20] = "hello world"; // 用数组存的字符串, 是变量, 可以修改

}

int main()
{
    // MAX = 200;
    // test9();
    // int arr[5] = {1, 2, 3, 4, 5};
    // test11(arr, 5);
    test3();
    return 0;
}