#define _CRT_SECURE_NO_WARNINGS
#include "test.h"


// 函数的实现
void createQuestion()
{
	// 创建问题
	printf("开始创建问题\n");
	FILE* f_write = fopen("question.txt", "w");
	if (f_write == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	int num1, num2;
	char ch;
	char symbol[4] = { '+', '-', '*', '/' };
	// printf("大小： %d\n", sizeof(symbol));
	srand((size_t)time(NULL));
	for (int i = 0; i < 50; i++)
	{
		// 生成50个题目
		num1 = rand() % 100 + 1;
		num2 = rand() % 100 + 1;
		ch = symbol[rand() % 4];

		// 拼接字符成一个字符串, 写入文件
		char buf[64] = { 0 };
		sprintf(buf, "%d %c %d=\n", num1, ch, num2);
		// 按行写入文件
		fputs(buf, f_write);
	}
	fclose(f_write);
	printf("题目生成成功\n");
}

void answerQuestion()
{
	// 解答问题
}