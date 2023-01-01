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
    char buf4[14] = "hello world\n";
    // puts(buf4); // 带换行
    fputs(buf4, stdout); // 不带换行
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

 void test11(int a=10, int b = 20)
 {
    printf("a的值为: %d");
 }

int main()
{
    // MAX = 200;
    // test9();
    test10();
    return 0;
}