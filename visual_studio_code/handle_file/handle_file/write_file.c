#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
	// 打开文件
	FILE* f_write = fopen("test.txt", "w");
	if (f_write == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	// 写入字符
	char buf[32] = "hello world";
	int i = 0;
	while (buf[i] != 0)
	{
		printf("开始写入: %c\n", buf[i]);
		fputc(buf[i], f_write);
		i++;
	}
	// 关闭文件
	fclose(f_write);
}

int main()
{
	test1();
	return 0;
}