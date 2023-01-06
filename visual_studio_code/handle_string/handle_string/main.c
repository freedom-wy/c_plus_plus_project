#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1()
{
	// �ַ�������
	char dest1[20];
	char src[] = "hello world";
	strcpy(dest1, src);
	printf("��������ַ���Ϊ: %s\n", dest1);
	char dest2[20];
	strncpy(dest2, src, 2); // δ����\0, ���Ժ����ַ����� strncpy����n���ַ�
	dest2[2] = '\0'; // ���������ں������\0
	printf("��������ַ���Ϊ: %s\n", dest2);
	printf("�ַ�������Ϊ: %d\n", strlen(dest2));
	printf("�ַ�����ռ�ռ�Ϊ: %d\n", sizeof(dest2));
}

void test2()
{
	// �ַ����Ƚ�
	char str1[] = "hello world";
	char str2[32] = { '0' };
	printf("�������ַ���: \n");
	fgets(str2, sizeof(str2), stdin); // ��������
	str2[strlen(str2) - 1] = '\0'; // �����Ļ��з��޸�Ϊ\0
	if (strcmp(str1, str2) == 0)
	{
		printf("��ͬ");
	}
	else
	{
		printf("��ͬ");
	}
}

void test3()
{
	// �ַ���ƴ��
	char str1[32] = "hello"; // �趨���С
	char* str2 = " world"; // ����һ���ַ�������
	char str3[32] = " world";
	strcat(str1, str2); // ��str2ƴ�ӵ�str1��
	printf("�ַ���ƴ�ӽ��: %s\n", str1);
	strcat(str1, str3);
	printf("�ַ���ƴ�ӽ��: %s\n", str1);
}

void test4()
{
	// ��ʽ���ַ���
	int year = 2023;
	int month = 1;
	int day = 5;
	char buf[32] = { '0' };
	sprintf(buf, "%d��%d��%d��", year, month, day); // �ַ�����ֵ
	printf("��������ϢΪ: %s\n", buf);
}

void test5()
{
	// �ַ������
	char msg[128] = "phone:13412345678;2022/1/5;�û�Ǯ��";

	long long phone = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	char text[64] = { 0 };

	sscanf(msg, "phone:%lld;%d/%d/%d;%s", &phone, &year, &month, &day, text);

	printf("�ֻ���: %lld\n", phone);
	printf("���: %d\n", year);
	printf("�·�: %d\n", month);
	printf("����: %d\n", day);
	printf("��Ϣ: %s\n", text);
}

void test6()
{
	// �ַ�����
	char buf[32] = "test@test.com";
	char* ret = strchr(buf, '@'); // ����Ҫ�����ַ���ָ��
	if (ret == NULL)
	{
		printf("δ�ҵ��ַ�");
	}
	else
	{
		printf("�ҵ����ַ�, �ַ�λ��Ϊ: %d\n", ret - buf); //��0��ʼ��
	}
}

void test7()
{
	// �ַ������Һ��滻
	// char buf[1024] = { '0' };
	// fputs(buf, sizeof(buf), stdin);
	// char buf[1024] = "hello sb hello";
	// char* ret = strstr(buf, "sb"); //�����ַ���λ��, �����ַ���ָ��
	// printf("�ַ���λ��Ϊ: %d\n", ret - buf);

	// char buf[1024] = "hello sb, world";
	// char* ret = strstr(buf, "sb");
	//printf("�ַ���λ��: %d\n", ret - buf);
	// strncpy(ret, "**", 2);
	// printf("���κ���ַ���Ϊ: %s\n", buf);
	// char buf[1024] = "hello sb world";
	// char* ret = strstr(buf, "sb");
	//strncpy(ret, "**", 2);
	// printf("���κ���ַ���Ϊ: %s\n", buf);
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
			printf("���κ�Ľ��Ϊ: %s\n", buf);
			break;
		}
	}
}

void test8()
{
	char buf[1024] = "����:����:����:����:����";
	char* names[64] = { '0' };
	int i = 0;
	// char* ret = strtok(buf, ":");
	// printf("�ַ������Ϊ: %s\n", ret);
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
			printf("����Ϊ: %s\n", names[i]);
		}
	}

}

void test9()
{
	char str1[] = "123";
	int num = 0;
	num = atoi(str1);
	printf("ת���������Ϊ: %d\n", num);
}

int main()
{
	test8();
	return 0;
}