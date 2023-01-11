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
	// 先将题目读取出来
	FILE* f_read = fopen("question.txt", "r");
	if (f_read == NULL)
	{
		printf("问题文件打开失败\n");
		return;
	}

	// 将结果放入新文件中
	FILE* f_write = fopen("answer.txt", "w");
	if (f_write == NULL)
	{
		printf("答案文件打开失败\n");
		return;
	}

	int num1, num2;
	char ch;
	int result = 0;
	char buf[32] = { 0 };
	while (fgets(buf, sizeof(buf), f_read))
	{
		sscanf(buf, "%d %c %d", &num1, &ch, &num2);
		if (ch == '+')
		{
			result = num1 + num2;
		}
		if (ch == '-')
		{
			result = num1 - num2;
		}
		if (ch == '*')
		{
			result = num1 * num2;
		}
		if (ch == '/')
		{
			result = num1 / num2;
		}

		// 将结果重新拼接
		char buf1[32] = { 0 };
		sprintf(buf1, "%d %c %d=%d\n", num1, ch, num2, result);
		fputs(buf1, f_write);
	}
	fclose(f_write);
	fclose(f_read);
	printf("解答完毕");
}