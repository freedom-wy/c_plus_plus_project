#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MySwap(int* p1, int* p2)
{
    // �޷�����
    /*int* pTmp = p1;
    p1 = p2;
    p2 = pTmp;*/
    // ����Ҫ�м�ӷ��ʲŻ��н���
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    // ��ַ���ݴ��
    int a = 1;
    int b = 2;
    MySwap(&a, &b);
    printf("������a=%d, b=%d\n", a, b);
    return 0;
}