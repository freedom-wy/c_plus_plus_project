#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int &ref)
{
    ref++;
}


int main()
{
    /*int n = 100;

    int* p1 = NULL;
    char* p2 = NULL;
    short* p3 = NULL;

    p1 = &n;
    p2 = (char*)&n;
    p3 = (short*)&n;

    printf("%d\n", *p1);
    printf("%d\n", *p2);
    printf("%d\n", *p3);*/

    /*char ary[5] = {'a', 'b', 'c', 'd', 'e'};
    
    int* p1 = NULL;
    char* p2 = NULL;
    short* p3 = NULL;

    p1 = (int*)ary;
    p2 = (char*)ary;
    p3 = (short*)ary;

    p1++; // �ƶ�4���ֽ�
    p2++; // �ƶ�1���ֽ�
    p3++; // �ƶ�2���ֽ�*/
    
    /*int n = 100;
    int* p1 = NULL;
    int &ref = n; // refΪn������
    p1 = &n;
    add(ref);*/

    /*int* p1 = NULL;
    int* p2 = NULL;
    p2 = &p1[8];
    printf("p2=%d\n", *p2);*/

    char* p1 = NULL;
    p1 = "hello world";
    printf("%p\n", p1);
    p1[0] = 'H';
    printf("%s\n", p1);


	return 0;
}