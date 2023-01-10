#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
    union DATA
    {
        int a;
        short b;
        char c;
    };

    union DATA data;
    data.a = 10;
    data.b = 20;
    data.c = 30;
    printf("data.a的值为: %d\n", data.a); // 30 谁用这块空间, 值就是多少, 最后一次赋值为30
    printf("求和: %d\n", data.a+data.b+data.c); // 值为90, 30+30+30
    // 如果数据超出数据类型空间大小, 按照数据类型空间大小存储数据
}

void test2()
{
    // 创建枚举类型, 如不赋初始值, 则从0开始, 每个变量递增, 定义后不可修改
    enum PUKER
    {
        HONGTAO = 100,
        HEITAO,
        MEIHUA,
        FANGPIAN
    };

    enum PUKER puker;
    puker = HONGTAO;
    printf("红桃的值为: %d\n", puker);
    printf("黑桃的值为: %d\n", HEITAO);
    printf("梅花的值为: %d\n", MEIHUA);
    printf("方片的值为: %d\n", FANGPIAN);
}

void test3()
{
    // 别名
    typedef int MYINT;
    int a = 10;
    MYINT b = 20;
    printf("a的值为: %d\n", a);
    printf("b的值为: %d\n", b);

    struct Person
    {
        int age;
        char name[64];
    };

    struct Person p1 = {18, "hello"};

    printf("年龄: %d, 姓名: %s\n", p1.age, p1.name);

    typedef struct Person person; // 对结构体定义别名
    person p2 = {20, "world"}; // 简化结构体类型长度
    printf("年龄: %d, 姓名: %s\n", p2.age, p2.name);

    // 另一种简化方式
    typedef struct Teacher
    {
        int age;
        char name[64];
    }teacher; // 此时teacher不是变量名, 而是类型别名

    teacher t1 = {22, "李先生"};
    printf("年龄: %d, 姓名: %s\n", t1.age, t1.name);
}

void test4()
{
    char* p1, p2; // 如果要都为指针则为 char *p1, *p2;
    printf("p1的大小为: %d\n", sizeof(p1)); // 8
    printf("p2的大小为: %d\n", sizeof(p2)); // 1

    typedef char* CHAR;
    CHAR p3, p4;
    printf("p3的大小为: %d\n", sizeof(p3)); // 8
    printf("p4的大小为: %d\n", sizeof(p4)); // 8
}

int main()
{
    test4();
    return 0;
}