#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testAdd(int a, int b)
{
    return a+b;
}

// ͨ��typedef�����µ�����
typedef int(*PFNTESTADD)(int, int);

int main()
{
    PFNTESTADD pfntestAdd = NULL;
    //int(*p)(int, int)=NULL; // ����һ������ָ��
    pfntestAdd = testAdd; // ָ�������ֵ
    int c = (*pfntestAdd)(1, 2); // ָ�뺯�����úʹ���
    printf("c=%d\n", c);
    return 0;
}