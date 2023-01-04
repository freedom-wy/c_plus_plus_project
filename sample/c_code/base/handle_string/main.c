#include <stdio.h>
#include <string.h>


void test1()
{
    // char dest[20] = {'0'};
    char dest[20]; // 长度需足够, 否则会报错
    char src[] = "hello world"; // 包含\0
    strcpy(dest, src);
    printf("%s\n", dest);
    printf("dest的sizeof值为: %d\n", sizeof(dest));
    printf("dest的strlen的值为: %d\n", strlen(dest));
    for(int i=0; i<sizeof(dest); i++)
    {
        printf("字符值为: %c\n", dest[i]);
    }
}

void test2()
{
    // char dest[20] = {'0'};
    char dest[20]; // 由于未初始化0, 通过strncpy对限定长度拷贝时, 会输出乱码
    char src[] = "hello world";
    strncpy(dest, src, 5);
    printf("%s\n", dest);
    for(int i = 0; i<sizeof(dest); i++)
    {
        printf("字符值为: %c\n", dest[i]);
    }
}

void test3()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    // if(str1 == str2) // 字符串不能使用这种方式进行对比, 需要使用strcmp
    // if(strcmp(str1, str2) == 0)
    // {
    //     printf("字符串相等\n");
    // }
    char str3[32] = {'0'};
    fgets(str3, sizeof(str3), stdin); // 输入数据并给str3赋值
    str3[strlen(str3)-1] = '\0'; //处理最后的换行符, 修改为\0
    if (strcmp(str1, str3) == 0) // strncmp 只比较n个字符 strncmp(str1, str2, n)
    {
        printf("输入的字符串相同\n");
    }
    else
    {
        printf("输入的字符串不同\n");
    }
}

void test4()
{
    // 字符串拼接
    char str1[] = "hello";
    char str2[] = " world";
    printf("字符串拼接结果: %s\n", strcat(str1, str2));
}


int main()
{
    test4();
    return 0;
}