#### �޷�������
```txt
�޷�������ռ4���ֽ�, ��8��16��������ɣ����޷������Ͳ���32λʱ����0������λ
```
#### �з�������
```txt
�з���������������ʾ���ŵ������λ, ������λ, ���λΪ0��ʾ����, ���λΪ1��ʾ����, �з������������Բ�����ʽ�洢�ġ�
```
#### ����
```txt
�������ڴ��ж����Բ������ʽ��ŵ�
-3
ԭ�� 10000000 00000000 00000000 00000011
���� 11111111 11111111 11111111 11111100
���� 11111111 11111111 11111111 11111101
16����  FFFFFFFD

3
ԭ�� 00000000 00000000 00000000 00000011
���� 00000000 00000000 00000000 00000011
���� 00000000 00000000 00000000 00000011
16����  00000003

```
#### ������
```txt
float�������ڴ���ռ4���ֽ�, ���λ���ڱ�ʾ����, ��ʣ��31λ��, ��������ȡ8λ��ʾָ��, �����ʾβ��
12.25fת��Ϊ��������1100.01   С�����ֳ���2    0.25*2=0.5��Ϊ0, 0.5*2=1 ��Ϊ1
��λ С���������ƶ�, �ƶ�Ϊ1.10001, ���ƶ���3��
����λ 0
ָ��λ 3+127=130ת��Ϊ������Ϊ10000010
β��λ 10001 00000000000000000000000
ƴ�� 0100 0001 0100 0100 0000 0000 0000 0000 0000 0 ת��16����41440000, Сβ 00004441

895.75ת��Ϊ��������Ϊ1101111111.11
��λ 1.10111111111, �ƶ���9��
����λ 0
ָ��λ 9+127=136 ת��Ϊ������Ϊ10001000
β��λ 10111111111000000000000
ƴ�� 0100 0100 0101 1111 1111 0000 0000 0000  ת����16���� 445ff000, Сβ 00f05f44

-0.125fת��Ϊ������Ϊ 0.125*2��Ϊ0 0.25*2��Ϊ0 0.5*2��Ϊ1 ���Ϊ0.001
��λ1.0 �����ƶ���3λ
����λ 1
ָ��λ 127-3 ת��Ϊ������λ 01111100
β��λ 00000000000000000000000
ƴ�� 1011 1110 0000  0000 0000 0000 0000 0000 ת����16���� BE 00 00 00 Сβ 000000BE
```
#### 
```txt
ÿһ����������ջ����һ��ռ�
һ�����յ���Լ������, ����Լ��: 1�������Ĵ��ݷ���, �����Ĵ洢ý��, ˭����ƽ�����(�ͷŲ����ռ�), ����ֵ�Ĵ���
Լ��������:
1��__cdecl: Ĭ��Լ��, �������󴫲�, ����ͨ��ջ����, ���÷�������������ռ�(֧�ֲ�������)
2��__fastcall: �������󴫲�, ����ǰ��������ͨ�����������, �������ͨ��ջ����, ������������������ռ�(֧�ֲ�������)
3��__stdcall: ΢�����, �������󴫲�, ����ͨ��ջ����, ������������������ռ�(��֧�ֲ�������)

������ջ�����淵�ص�ַ, ���ڴ���,���Դ�Ŷ��������ջ�ռ䣬�����ú�����ջ�ռ��ڵ��ú���ջ�ռ�����, �������ջ������
����������÷���ջ��Ϣ, ����ִ���걻���ú����󷵻ص��ú���
�ġ�����ջλ��(�ڴ�������)�������÷�ջ�״�
�塢��ջ�ڿ��پֲ������Ŀռ�
��.һ������ѡ����/Zi+/Od, �����ֲ������ռ�Ϊ0xcc
�������洦��������
�ߡ�ִ�к�����
�ˡ��ָ�����������
�š��ͷžֲ������ռ�
ʮ���ָ�ջ��Ϣ�����÷�
ʮһ.һ��ȡ�����ص�ַ�����������̸���, �ִ��µ�ַ���ɵ��÷��������, __cdecl
ʮһ.����ȡ�����ص�ַ�����������Ȼ�󰴷��ص�ַ�����̸���, __stdcall, __fastcall
```
#### �������ַ��ʽ ʮ�����Ƽ���
```txt
Int i[5]����֪i���׵�ַ��0012FF6C����i[4]
0012FF6C+4��4= 0012FF6C+10��ʮ������16��= 0012FF7C

ary:0x0019ff1c
int n=8
ary[3]=0x0019FF28
ary[n]=0x0019FF3C
ary[n-5]=0x0019FF28
ary[5-n]=0x0019FF10


��ά�������ַ
������������ַ
�����ڲ������ַ

int arr[M][N];
�� arr[1][2]�ĵ�ַ
�����׵�ַ+sizeof(type[N])*1+sizeof(type)*2
```
#### �ַ���
```txt
ASCII��ʾ�ַ� char ch1 = 'a'; // һ���ֽ�
UNICODE��ʾ�ַ� short int ch2 = L'a'; // �����ֽ�

char szBuf[] = "hello"; // ��strcpy����
unsigned short int wszBuf[] = L"Hello"; // ��wcscpy����

printf("%s\n", szBuf);
wprintf(l"%s\n", wszBuf);

```
#### ȫ�ֱ���
```txt
ȫ�ֱ�����link�׶�д���ִ���ļ�
00400000 ��ִ���ļ�װ�����ڴ��е�λ�ý�ģ���ַ
```
#### ��̬ȫ�ֱ���
```txt
���﷨Լ����ȫ�ֱ���, �ڵ�ǰ�ļ�����Ч
```
#### ��̬�ֲ�����
```txt
���﷨Լ����ȫ�ֱ���, �ڵ�ǰ��������Ч
```
```c
#include <iostream>
using namespace std;


// ��c++�У��޷����ڴ��й۲⵽��̬�ֲ��������ݣ���c�п���

// ��C++�п���ͨ�����ַ����Գ������г�ʼ��, ��C�в���
int getInt()
{
    return 1;
}

int g_a = getInt();
// cout << "ȫ�ֱ���ֵΪ: " << g_a << endl;
// printf("ȫ�ֱ���ֵΪ: %d\n", g_a);


void foo()
{
    static char str[] = "hello world";
    // cout << "foo�о�̬����ֵΪ: " << str << endl;
    printf("foo�о�̬����Ϊ: %s\n", str);
}


int main()
{
    foo();
    static int a = 100;
    // cout << "main�о�̬����ֵΪ: " << a << endl;
    printf("foo�о�̬����Ϊ: %d\n", a);
    return 0;
}
```
```c
// ��C�пɹ۲⾲̬�ֲ���������, ��C++���޷��۲�
#include <stdio.h>


static char g_szBuf[] = "Hello CR40!";

extern void foo();

// ��C�������޷�ͨ���÷�����ȫ�ֱ�����ֵ
/*int GetInt()
{
	return 0x87654321;
}

int g_nTest = GetInt();*/


int main()
{
    static int stcnTest = 100;
	foo();

    return 0;
}

void foo()
{
    static int stcnTest = 0x88888888;
	printf("%d",stcnTest);
}
```
```c++
// ��̬��������ʼ��һ�Σ����ڴ����б�ʶ�����޸ı�ʾ���þ�̬�����ظ���ֵ
#include <stdio.h>

void foo(int num)
{
    static int val = num;
    printf("ֵΪ: %d\n", val);
    printf("��ַΪ: %p\n", &val);
    printf("��ַΪ: %p\n", &(&val)[-1]);
    (&val)[-1] = 0;
}


int main()
{
    foo(10);
    foo(20);
    foo(30);
    return 0;
}
```
#### �궨��
```txt
�궨����#define �������޷ֺ�
�вκ�Ҳ�б��ʽ�� #define GET_AREA(r) ((r)*(r)*3.14)
```
```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����6.0���ظ�����forѭ���б�����ͻ����
#define for if(1)for
// ת����, ͨ��if������
/*
if(1)
{
    for(int i=0;i<5;i++)
        {
            printf("hello world\n");
        }
}
*/

int main()
{
    // ��visual c++6.0���Ǿֲ�������
	for(int i=0;i<5;i++)
    {
        printf("hello world\n");
    }
	for(int i=0;i<5;i++)
    {
        printf("hello world\n");
    }
    return 0;
}
```
```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define while if // ��while�滻Ϊif
/*
int main()
{
    int i = 0;
    if (i<5)
    {
        printf("hello world\n");
        i++;
    }
    return 0;
}
*/

int main()
{
    int i = 0;
    while (i<5)
    {
        printf("hello world\n");
        i++;
    }
    return 0;
}
```
#### ͨ�������ظ���������
```c
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1.h"
#include "test1.h"
#include "test1.h"

int main()
{
    printf("a=%d\n", a);
    return 0;
}

// test1.h
// guidgen
// #pragma once
#ifndef KR_94B9BDB0_2B69_4202_8179_13CA7205E622
#define KR_94B9BDB0_2B69_4202_8179_13CA7205E622
int a = 100;
#endif // KR_94B9BDB0_2B69_4202_8179_13CA7205E622
```
#### ָ��
```txt
ָ��������ĵ�ַ����ַ��һ����ָ��
ָ��ֻ�����˴�����ݵ��׵�ַ����û��ָ���������������������ͼ�Ϊ����ָ�����������
ָ�뱣����ǵ�ַ���������ʲô���͵�ָ�룬32λ����ռ��4�ֽڣ�64λ����ռ��8�ֽ�

++p�õ�ָ�����
p++�õ�ָ�볣��
```
```c
char ary[5] = {'a', 'b', 'c', 'd', 'e'};
    
int* p1 = NULL;
char* p2 = NULL;
short* p3 = NULL;

p1 = (int*)ary;
p2 = (char*)ary;
p3 = (short*)ary;

p1++; // �ƶ�4���ֽ�
p2++; // �ƶ�1���ֽ�
p3++; // �ƶ�2���ֽ�
```
```txt
�޸�WRES���򿪶������ļ����ҵ�rdata�����а룬��40��4ת��Ϊ������0100���޸�Ϊ1100����ΪC0���������޸�
```
#### ָ�뺯��
```txt
���ڱ��溯���׵�ַ��ָ���������Ϊ����ָ��
���ܷ��ؾֲ������Ͳ�����ַ
```
```c
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
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int testAdd(int a, int b)
{
    return a+b;
}

// ͨ��typedef�����µ�����
typedef int(*PFNTESTADD)(int, int);*/


void SortA(int aryCard[], int nCount)
{
    printf("A���򷽷�\n");
}

void SortB(int aryCard[], int nCount)
{
    printf("B���򷽷�\n");
}

// ͨ��typedef���庯��ָ�����
typedef void (*PFNSORT)(int [], int);

void PlayCard(int aryCard[], int nCount, PFNSORT pfnSort=NULL)
{
    // ϴ��
    pfnSort(aryCard, nCount);
}



int main()
{
    /*PFNTESTADD pfntestAdd = NULL;
    //int(*p)(int, int)=NULL; // ����һ������ָ��
    pfntestAdd = testAdd; // ָ�������ֵ
    int c = pfntestAdd(1, 2); // ָ�뺯�����úʹ���
    printf("c=%d\n", c);*/
    
    int card[54];
    PlayCard(card, 54, SortA);
    return 0;
}
```
#### ָ������
```txt
�������������0��Ԫ�����͵ĵ�ַ����
�������������Ϊָ�룬����������ָ�����͵ĵ�ַ��������ָ��ĵ�ַ����**
```
```c
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
```
#### �ṹ��
```txt
����������뷽ʽΪZp��Ĭ��Ϊ8
���Ա�������ṹ��֮��ĵ�ַ��Ϊmember offset
member��������	member offset % min(Zp,sizeof(member type)) == 0;

��ṹ���������ΪStructAlign
stryctAlign��������
StructAlign = max(sizeof(member1 type),sizeof(member2 type)������,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(�ṹ�����)��������
sizeof(�ṹ�����)%structAlign == 0;


�ṹ��Ѱַ��ʽ���ṹ���׵�ַ+��Աƫ����
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
��offsetof�ؼ���չ����Ľ����ͬ��
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
����������뷽ʽΪZp��Ĭ��Ϊ8
���Ա�������ṹ��֮��ĵ�ַ��Ϊmember offset
member��������	member offset % min(Zp,sizeof(member type)) == 0;

��ṹ���������ΪStructAlign
stryctAlign��������
StructAlign = max(sizeof(member1 type),sizeof(member2 type)������,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(�ṹ�����)��������
sizeof(�ṹ�����)%structAlign == 0;


�ṹ��Ѱַ��ʽ���ṹ���׵�ַ+��Աƫ����
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
��offsetof�ؼ���չ����Ľ����ͬ��
*/


struct tagDateOfBirth // �������Ϊ4
{
    int nYear; // +0
    short int wMonth; // +4
    char cDay; // +6
}; // 7 % 4 == 0 ���sizeofΪ8

// ����ṹ��
struct tagStuInfo 
{
    char szName[5]; // +0 // 8 % min(8,sizeof(char)) == 0;
    float fHeight; // +8
    short int wScore; // +12
    int nAge; // +16
    char cGender; // +20
    double dblWeight; // +24
    struct tagDateOfBirth dob; // ����ΪStructAlignΪ4 // +32
}; // 40 % 8 ==0 ���sizeof Ϊ40

int main()
{
    int a = 100;
    struct tagStuInfo s1;
    strcpy(s1.szName, "abc");
    s1.fHeight = 185.0f;
    s1.wScore = 65;
    s1.nAge = 18;
    s1.cGender = 'U';
    s1.dblWeight = 75.0;
    s1.dob.nYear = 2023;
    s1.dob.wMonth = 3;
    s1.dob.cDay = 17;

    printf("sizeof tagStuInfo s1 = %d\n", sizeof(s1)); // 40
    return 0;
}
```
#### ������ ö��
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum eScoreType
{
    TY_FLOAT,
    TY_INT,
    TY_CHAR,
    TY_TEXT
};

union tagScore
{
    float fScore;
    int nScore;
    char chLevel;
    char* pszText;
};

struct data
{
    // int nType;
    enum eScoreType nType;
    union tagScore s1;
};

void ShowScore(struct data d1)
{
    switch(d1.nType)
    {
    case TY_FLOAT:
        printf("%f\n", d1.s1.fScore);
        break;
    case TY_INT:
        printf("%d\n", d1.s1.nScore);
        break;
    case TY_CHAR:
        printf("%c\n", d1.s1.chLevel);
        break;
    case TY_TEXT:
        printf("%s\n", d1.s1.pszText);
        break;
    }
}


int main()
{
    struct data d1;
    d1.nType = TY_FLOAT;
    d1.s1.fScore = 59.9f;
    ShowScore(d1);

    struct data d2;
    d2.nType = TY_INT;
    d2.s1.nScore = 100;
    ShowScore(d2);

    return 0;
}
```











