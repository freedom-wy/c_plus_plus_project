#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1()
{
	// 字符串拷贝
	char dest1[20];
	char src[] = "hello world";
	strcpy(dest1, src);
	printf("拷贝后的字符串为: %s\n", dest1);
	char dest2[20];
	strncpy(dest2, src, 2); // 未拷贝\0, 所以后面字符乱码 strncpy拷贝n个字符
	dest2[2] = '\0'; // 按照索引在后面添加\0
	printf("拷贝后的字符串为: %s\n", dest2);
	printf("字符串长度为: %d\n", strlen(dest2));
	printf("字符串所占空间为: %d\n", sizeof(dest2));
}

void test2()
{
	// 字符串比较
	char str1[] = "hello world";
	char str2[32] = { '0' };
	printf("请输入字符串: \n");
	fgets(str2, sizeof(str2), stdin); // 数据输入
	str2[strlen(str2) - 1] = '\0'; // 将最后的换行符修改为\0
	if (strcmp(str1, str2) == 0)
	{
		printf("相同");
	}
	else
	{
		printf("不同");
	}
}

void test3()
{
	// 字符串拼接
	char str1[32] = "hello"; // 需定义大小
	char* str2 = " world"; // 定义一个字符串常量
	char str3[32] = " world";
	strcat(str1, str2); // 将str2拼接到str1上
	printf("字符串拼接结果: %s\n", str1);
	strcat(str1, str3);
	printf("字符串拼接结果: %s\n", str1);
}

void test4()
{
	// 格式化字符串
	int year = 2023;
	int month = 1;
	int day = 5;
	char buf[32] = { '0' };
	sprintf(buf, "%d年%d月%d日", year, month, day); // 字符串赋值
	printf("年月日信息为: %s\n", buf);
}

void test5()
{
	// 字符串拆分
	char msg[128] = "phone:13412345678;2022/1/5;该还钱了";

	long long phone = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	char text[64] = { 0 };

	sscanf(msg, "phone:%lld;%d/%d/%d;%s", &phone, &year, &month, &day, text);

	printf("手机号: %lld\n", phone);
	printf("年份: %d\n", year);
	printf("月份: %d\n", month);
	printf("日期: %d\n", day);
	printf("消息: %s\n", text);
}

void test6()
{
	// 字符查找
	char buf[32] = "test@test.com";
	char* ret = strchr(buf, '@'); // 返回要查找字符的指针
	if (ret == NULL)
	{
		printf("未找到字符");
	}
	else
	{
		printf("找到了字符, 字符位置为: %d\n", ret - buf); //从0开始算
	}
}

void test7()
{
	// 字符串查找和替换
	// char buf[1024] = { '0' };
	// fputs(buf, sizeof(buf), stdin);
	// char buf[1024] = "hello sb hello";
	// char* ret = strstr(buf, "sb"); //查找字符串位置, 返回字符串指针
	// printf("字符串位置为: %d\n", ret - buf);

	// char buf[1024] = "hello sb, world";
	// char* ret = strstr(buf, "sb");
	//printf("字符串位置: %d\n", ret - buf);
	// strncpy(ret, "**", 2);
	// printf("屏蔽后的字符串为: %s\n", buf);
	// char buf[1024] = "hello sb world";
	// char* ret = strstr(buf, "sb");
	//strncpy(ret, "**", 2);
	// printf("屏蔽后的字符串为: %s\n", buf);
	char buf[1024] = { '0' };
	fgets(buf, sizeof(buf), stdin);
	char* p = buf;
	while (1)
	{
		char* ret = strstr(p, "sb");
		if (ret != NULL)
		{
			strncpy(ret, "**", 2);
			p = p + 2;
		}
		else
		{
			printf("屏蔽后的结果为: %s\n", buf);
			break;
		}
	}
}

void test8()
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
		if (names[i] != NULL)
		{
			printf("名称为: %s\n", names[i]);
		}
	}

}

void test9()
{
	char str1[] = "123";
	int num = 0;
	num = atoi(str1);
	printf("转换后的数字为: %d\n", num);
}

int main()
{
	test8();
	return 0;
}