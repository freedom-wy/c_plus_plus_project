#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int val)
{
    return val;
}

int main()
{
    int a = 100;
    foo(a);
    printf("hello world\n");
    return 0;
}