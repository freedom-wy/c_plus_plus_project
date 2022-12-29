#include <stdio.h>
#include <time.h>


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
    printf("字符串为: %s\n", buf2);
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

int main()
{
    test5();
    return 0;
}