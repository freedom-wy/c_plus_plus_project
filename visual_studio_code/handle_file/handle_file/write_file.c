#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
	// ���ļ�
	FILE* f_write = fopen("test.txt", "w");
	if (f_write == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	// д���ַ�
	char buf[32] = "hello world";
	int i = 0;
	while (buf[i] != 0)
	{
		printf("��ʼд��: %c\n", buf[i]);
		fputc(buf[i], f_write);
		i++;
	}
	// �ر��ļ�
	fclose(f_write);
}

int main()
{
	test1();
	return 0;
}