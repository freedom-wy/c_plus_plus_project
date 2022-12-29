#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int num = 0;
    printf("请重新给num赋值: ");
    scanf("%d", &num);
    printf("num的新值为: %d\n", num);

    getchar(); // 从缓冲区获取一个字符

    char ch = 'a';
    printf("请重新给ch进行赋值: ");
    scanf("%c", &ch); // 如果是字符串, 则不需要通过&取地址, 字符串为字符数组, 返回字符串中首个字符地址
    printf("ch的新值为: %c\n", ch);
}

void test2()
{
    int abc = 10;
    printf("abc='%6d'\n", abc); // 6调整数据输出宽度
}

void test3()
{
    // 从右向左运算
    int a= 10;
    // a+=a*=a+=a+=a/=a*=a+=a;
    // a+= a*= a+= a+= a/= a*= a+=a; 32
    printf("a的值为: %d\n", a);
}

void test4()
{
    // 隐式转换 int转char
    int num = 353; // 转成2进制为9位, 一个ch为1个字节8位, 舍弃最高位, 最终放入的二进制转成10进制为97, 因此输出为a
    char ch = num;
    printf("%c\n", ch);
}

void test5()
{
    // 强制类型转换
    float f = 3.14f;
    int num = 0;
    // num = (int)f; // 强制类型转换
    num = f;
    printf("num的值为: %d\n", num);
}

void test6()
{
    int a = 1;
    int b = 2;
    int c = a>b?a:b;
    printf("c的值为: %d\n", c);
}


int main()
{
    // printf("hello world\n");
    // system("ls");
    // int a = 10;
    // int b = sizeof(a);
    // size_t c = sizeof(a);
    // printf("%d\n", b);
    // printf("%u\n", c);
    // int a;
    // printf("请输入a的值: ");
    // scanf("%d", &a);
    // printf("%d\n", a);
    // 字符型, 用单引号
    // char ch = 'a';
    // printf("字符为: %c\n", ch);
    // printf("ascii值为: %d\n", ch);
    // 小写字母转大写字母a 97-32=65 A
    // printf("3.14占空间大小为: %d\n", sizeof(3.14)); //8个字节 double
    // printf("%s\n", "hello world");
    // char str[] = "hello world";
    // printf("占用空间大小为: %d\n", sizeof(str));
    // test1();
    test6();
    return 0;
}