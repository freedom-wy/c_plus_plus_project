#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 对字符串加解密
char str1[] = "hello world";

char* Encrypt(char* str, char* secretKey)
{
	// 加密
	for (size_t i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] ^ secretKey[i % strlen(secretKey)];
	}
	return str;
}

char* Decrypt(char* str, char* secretKey)
{
	// 解密
	for (size_t i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] ^ secretKey[i % strlen(secretKey)];
	}
	return str;
}

// 对文件加解密



void test1()
{
	int a = 0b00000001;
	int b = 0b00000010;
	int c = a ^ b; // int c = 0b00000011
	/*
		0b00000011
		0b00000010
		0b00000001
	*/
	printf("0X%x\n", c);
}

void test2()
{
	char secretKey[] = "abc";
	char* str2 = Encrypt(str1, secretKey);
	printf("%s\n", str2);
	char* str3 = Decrypt(str2, secretKey);
	printf("%s\n", str3);
}

void test3()
{
	FILE* f_read = fopen("source.txt", "r");
	FILE* f_write = fopen("dest.txt", "a+");
	if (f_read == NULL)
	{
		printf("f_read文件打开失败\n");
		return 0;
	}
	if (f_write == NULL)
	{
		printf("f_write文件打开失败\n");
		return 0;
	}
	char c = 'a';
	while ((c = fgetc(f_read)) != EOF)
	{
		c = c ^ 'a';
		fputc(c, f_write);
	}
	fclose(f_read);
	fclose(f_write);
}

void test4()
{
	FILE* f_read = fopen("dest.txt", "r");
	FILE* f_write = fopen("source1.txt", "a+");
	if (f_read == NULL)
	{
		printf("f_read文件打开失败\n");
		return 0;
	}
	if (f_write == NULL)
	{
		printf("f_write文件打开失败\n");
		return 0;
	}
	char c = 'a';
	while ((c = fgetc(f_read)) != EOF)
	{
		c = c ^ 'a';
		fputc(c, f_write);
	}
	fclose(f_read);
	fclose(f_write);
}

int main()
{
	//test2();
	//test3();
	// test4();
	return 0;
}