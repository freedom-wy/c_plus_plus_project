#include <stdio.h>

int* test1()
{
	// ���ܷ��ؾֲ������ĵ�ַ
	int a = 10;
	return &a;
}

int main()
{

	int* a = test1();
	
	printf("a��ֵΪ: %d\n", *a);
	printf("a��ֵΪ: %d\n", *a);
	printf("a��ֵΪ: %d\n", *a);
	printf("a��ֵΪ: %d\n", *a);
	printf("a��ֵΪ: %d\n", *a);
	return 0;
}