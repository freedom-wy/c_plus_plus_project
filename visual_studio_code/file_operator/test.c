#define _CRT_SECURE_NO_WARNINGS
#include "test.h"


// ������ʵ��
void createQuestion()
{
	// ��������
	printf("��ʼ��������\n");
	FILE* f_write = fopen("question.txt", "w");
	if (f_write == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	int num1, num2;
	char ch;
	char symbol[4] = { '+', '-', '*', '/' };
	// printf("��С�� %d\n", sizeof(symbol));
	srand((size_t)time(NULL));
	for (int i = 0; i < 50; i++)
	{
		// ����50����Ŀ
		num1 = rand() % 100 + 1;
		num2 = rand() % 100 + 1;
		ch = symbol[rand() % 4];

		// ƴ���ַ���һ���ַ���, д���ļ�
		char buf[64] = { 0 };
		sprintf(buf, "%d %c %d=\n", num1, ch, num2);
		// ����д���ļ�
		fputs(buf, f_write);
	}
	fclose(f_write);
	printf("��Ŀ���ɳɹ�\n");
}

void answerQuestion()
{
	// �������
	// �Ƚ���Ŀ��ȡ����
	FILE* f_read = fopen("question.txt", "r");
	if (f_read == NULL)
	{
		printf("�����ļ���ʧ��\n");
		return;
	}

	// ������������ļ���
	FILE* f_write = fopen("answer.txt", "w");
	if (f_write == NULL)
	{
		printf("���ļ���ʧ��\n");
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

		// ���������ƴ��
		char buf1[32] = { 0 };
		sprintf(buf1, "%d %c %d=%d\n", num1, ch, num2, result);
		fputs(buf1, f_write);
	}
	fclose(f_write);
	fclose(f_read);
	printf("������");
}