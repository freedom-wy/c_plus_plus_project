#include <stdio.h>

// extern int g_a; // 有作用域

// void test1()
// {
//     extern int g_a; // 只能在test1中使用
//     printf("g_a的值为: %d\n", g_a);
// }

int* test2()
{
    static int s_a = 100;
    return &s_a;
}

void test3()
{
    // 静态局部变量作用范围{}, 声明周期为程序结束后释放
    static int s_b = 200;
    s_b++;
    printf("s_b的值为: %d\n", s_b);
}

void test4()
{
    extern void hello_world();
    hello_world();
}

int main()
{
    // 声明有一个全局变量, 可以到其他文件中查找, 编译时需多文件编译gcc -o main main.c test.c
    // extern int g_a;
    // test1();
    // printf("g_a的值为: %d\n", g_a);
    // int a; // 未赋值, 值内容为随机
    // printf("a的值为: %d\n", a);
    // test3();
    // test3();
    // test3();
    // test3();
    // test3();
    test4();
    return 0;
}