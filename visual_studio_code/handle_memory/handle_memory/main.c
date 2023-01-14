#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void setValue(int* pp)
{
	pp = malloc(sizeof(int));
	memset(pp, 0, sizeof(int));
	*pp = 100;
}

void test2()
{
	int* p = NULL;
	setValue(p);
	printf("aµÄÖµÎª: %d\n", *p);
}
int main()
{
	test2();
	return 0;
}