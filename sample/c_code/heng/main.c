#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 创建结构体
struct Person
{
    char* name;
    int age;
};

void test1()
{
    struct Person p1;
    // p1.name = malloc(sizeof(char)*32);
    // strcpy(p1.name, "heng");
    p1.name = "heng";
    p1.age = 20;
    printf("姓名: %s, 年龄: %d\n", p1.name, p1.age);
}


int main()
{
    test1();
    return 0;
}