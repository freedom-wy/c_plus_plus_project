#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int* func1()
{
	int a = 10;
	return &a;
}

int* func2()
{
	static int a = 10;
	return &a;
}

int* func3()
{
	int* tmp = NULL;
	tmp = (int*)malloc(sizeof(int));
	*tmp = 100;
	return tmp;
}

struct Stu
{
	char name[50];
	int age;
};

struct Stu s1 = { "zhangsan", 18 };

int main()
{
	
	return 0;
}