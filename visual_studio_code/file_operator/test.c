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
}