#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 对字符串加解密
char str1[] = "abcd1234";

char* Encrypt(char* str, char* secretKey)
{
	int str_len = strlen(str);
	// 加密
	for (size_t i = 0; i < str_len; i++)
	{
		str[i] = str[i] ^ secretKey[i % strlen(secretKey)];
	}
	return str;
}

char* Decrypt(char* str, char* secretKey)
{
	int str_len = 8;
	// 解密
	for (size_t i = 0; i < str_len; i++)
	{
		str[i] = str[i] ^ secretKey[i % strlen(secretKey)];
	}
	return str;
}

void test2()
{
	char secretKey[] = "abc";
	char* str2 = Encrypt(str1, secretKey);
	printf("%s\n", str2);
	char* str3 = Decrypt(str2, secretKey);
	printf("%s\n", str3);
}


// 对文件内容加解密

//// 获取文件大小
//int fsize(FILE* fp)
//{
//	fpos_t fpos; // 保存指针位置
//	fgetpos(fp, &fpos); // 获取当前指针位置
//	fseek(fp, 0, SEEK_END); // 移动指针到文件末尾
//	int n = ftell(fp); // 获取文件大小
//	fsetpos(fp, &fpos); // 恢复位置
//	return n;
//}
void EncryptAndDecryptFile(char* readFilePath, char* writeFilePath, char* secretKey)
{
	FILE* f_read = fopen(readFilePath, "r");
	if (f_read == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	// 按行读取文件内容
	while (!feof(f_read))
	{
		char buf[1024] = { '0' };
		char* p = fgets(buf, sizeof(buf)-1, f_read);
		if (p == NULL)
		{
			break;
		}
		buf[strlen(buf)] = '\0';
		// 加密数据
		char* encrypt_str = Encrypt(buf, secretKey);
		char* decrypt_str = Decrypt(encrypt_str, secretKey);
		printf("行内容: %s\n", decrypt_str);
	}
	fclose(f_read);
}



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



void test3()
{
	EncryptAndDecryptFile("test.txt", "abc", "abc");
}



int main()
{
	test2();
	return 0;
}