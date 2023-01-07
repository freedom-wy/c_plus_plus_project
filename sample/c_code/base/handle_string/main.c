#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test1()
{
    // char dest[20] = {'0'};
    char dest1[20]; // 长度需足够, 否则会报错
    char dest2[20];
    char src1[] = "hello world"; // 包含\0
    char src2[] = "hello\0world";
    strcpy(dest1, src1);
    strcpy(dest2, src2); //遇到\0停止, 为拷贝\0, 因此下面输出有乱码
    printf("%s\n", dest1);
    printf("%s\n", dest2);
    printf("dest的sizeof值为: %d\n", sizeof(dest2));
    printf("dest的strlen的值为: %d\n", strlen(dest2));
    for(int i=0; i<sizeof(dest2); i++)
    {
        printf("字符值为: %c\n", dest2[i]);
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

void test5()
{
    // char buf[1024] = "hello sb world";
    // char* ret = strstr(buf, "sb");
    // strncpy(ret, "**", 2);
    // printf("屏蔽后的字符串为: %s\n", buf);

    char buf[1024] = {'0'};
    fgets(buf, sizeof(buf), stdin);
    char* p = buf;
    while(1)
    {
        char* ret = strstr(p, "sb");
        if(ret != NULL)
        {
            strncpy(ret, "**", 2);
            p = p+2;
        }
        else
        {
            printf("屏蔽后的结果为: %s\n", buf);
            break;
        }
    }

}

void test6()
{
    char buf[1024] = "张三:李四:王五:赵六:陈七";
	char* names[64] = { '0' };
	int i = 0;
	// char* ret = strtok(buf, ":");
	// printf("字符串结果为: %s\n", ret);
    names[i] = strtok(buf, ":");
	while (names[i] != NULL)
	{
		i++;
		names[i] = strtok(NULL, ":");
	}

	for (int i = 0; i < sizeof(names) / sizeof(names[i]); i++)
	{
        if(names[i] != NULL)
        {
            printf("名称为: %s\n", names[i]);
        }
	}
}

void test7()
{
    char str1[] = "123";
    int num = 0;
    num = atoi(str1);
    printf("转换后的数字为: %d\n", num);
}

int main()
{
    test1();
    return 0;
}