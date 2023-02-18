#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int* func1()
{
	int a = 10;
	return &a;
}

int* func2()
{
	static int a = 10;
	return &a;
}

int* func3()
{
	int* tmp = NULL;
	tmp = (int*)malloc(sizeof(int));
	*tmp = 100;
	return tmp;
}

struct Stu
{
	char name[50];
	int age;
};

void test1()
{
	FILE* f_write = fopen("minnong.txt", "w");
	if (f_write == NULL)
	{
		printf("文件打开失败");
		return 0;
	}

	char* buf[] = {
		"锄禾日当午\n",
		"汗滴禾下土\n",
		"谁知盘中餐\n",
		"粒粒皆辛苦\n"
	};

	for (int i = 0; i < sizeof(buf) / sizeof(char*); i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);
}

void test2()
{
	FILE* f_read = fopen("minnong.txt", "r");
	if (f_read == NULL)
	{
		printf("文件打开失败\n");
		return 0;
	}

	char buf[1024] = { 0 };
	while (fgets(buf, sizeof(buf), f_read))
	{
		buf[strlen(buf) - 1] = '\0';
		printf("%s\n", buf);
	}
}

int main()
{
	test2();
	return 0;
}