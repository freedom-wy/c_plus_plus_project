#include <stdio.h>

void test1()
{
	// �ַ�������
	char dest1[20];
	char src[] = "hello world";
	strcpy(dest1, src);
	printf("��������ַ���Ϊ: %s\n", dest1);
	char dest2[20];
	strncpy(dest2, src, 2); // δ����\0, ���Ժ����ַ�����
	dest2[2] = '\0'; // ���������ں������\0
	printf("��������ַ���Ϊ: %s\n", dest2);
	printf("�ַ�������Ϊ: %d\n", strlen(dest2));
	printf("�ַ�����ռ�ռ�Ϊ: %d\n", sizeof(dest2));
}

int main()
{
	test1();
	return 0;
}