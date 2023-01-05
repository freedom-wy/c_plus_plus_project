#include <stdio.h>

void test1()
{
	// 字符串拷贝
	char dest1[20];
	char src[] = "hello world";
	strcpy(dest1, src);
	printf("拷贝后的字符串为: %s\n", dest1);
	char dest2[20];
	strncpy(dest2, src, 2); // 未拷贝\0, 所以后面字符乱码
	dest2[2] = '\0'; // 按照索引在后面添加\0
	printf("拷贝后的字符串为: %s\n", dest2);
	printf("字符串长度为: %d\n", strlen(dest2));
	printf("字符串所占空间为: %d\n", sizeof(dest2));
}

int main()
{
	test1();
	return 0;
}