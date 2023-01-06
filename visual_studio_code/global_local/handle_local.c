#include <stdio.h>

int* test1()
{
	// 不能返回局部变量的地址
	int a = 10;
	return &a;
}

int main()
{

	int* a = test1();
	
	printf("a的值为: %d\n", *a);
	printf("a的值为: %d\n", *a);
	printf("a的值为: %d\n", *a);
	printf("a的值为: %d\n", *a);
	printf("a的值为: %d\n", *a);
	return 0;
}