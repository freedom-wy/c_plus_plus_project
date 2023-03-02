// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int myAdd(int x, int y)
{
    return x+y;
}

int printValue(int x)
{
    int y = 1;
    printf("local value %d\n", y);
    return x;
}

int main(int argc, char* argv[])
{
	int a = 100;
    printf("&a=%08x\n", &a);
    int num = printValue(a);
    printf("num=%d\n", num);
    getchar();
	return 0;
}

/*
int main()
{
    int a = 100;
    printf("&a=%08x\n", &a);
    getchar();
    int b = 200;
    int sum = myAdd(a, b);
    printf("sum=%d\n", sum);
    getchar();
	return 0;
}
*/

