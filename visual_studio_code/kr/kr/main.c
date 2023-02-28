#include <stdio.h>

int main()
{
	int a = 0;
	printf("&a=%08x\n", &a);
	int* p1 = NULL;
	printf("&p1=%08x\n", &p1);
	system("pause");
	p1 = &a;
	*p1 = 100;
	printf("*p1=%d\n", *p1);
	printf("a=%d\n", a);
	system("pause");

	return 0;
}