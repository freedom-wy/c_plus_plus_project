### C����
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
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �޲�����
#define IN scanf
#define OUT printf

// ��������
#define PI 3.1415926f
#define S(r) PI*(r)*(r)

// ���ų�����
#define FILE_OPEN_ERROR -1

// #define ISDEBUG 1

void defineInOut()
{
    char str[20];
    IN("%s", str);
    // int strLen = strlen(str);
    // str[strLen] = '\0';
    OUT("%s\n", str);
}

void definePiS()
{
    float r;
    IN("%f", &r);
    float circle_s = S(r);
    printf("result = %f\n", circle_s);
}

int defineOpenFile()
{
    FILE* fp = fopen("test.txt", "r");
    if (fp==NULL)
    {
        return FILE_OPEN_ERROR;
    }
    fclose(fp);
    return 0;
}

void defineDebug()
{
    // __FILE__ �ļ����� __LINE__ �ļ�����
    // ����Ԥ����, ��debug�����ж���
#ifdef _DEBUG
    printf("%s:%d\n", __FILE__, __LINE__);
#endif
}

int main()
{
    // defineInOut();
    // definePiS();
    // int openCode = defineOpenFile();
    // printf("%d\n", openCode);
    defineDebug();
    return 0;
}
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
#### ����Ƕ�׵���
```c
#include <string.h>
 
int fun3(int x, float y)
{
    int n = 30;
    float m = 15.3f;
    return 0;
}
int fun2(int x)
{
    int n = 20;
    float m = 14.3f;
    fun3(n, m);
    return 0;
}
int fun1(int *p)
{
    int n = 10;
    float m = 13.8f;   
    fun2(10);
    return 0;
}
int main()
{
    struct tagTest
    {
        char ch;
        float f;
        double d;
        char strBuf[5];
        int n;       
    }test;
    test.ch = 'B';
    test.f = 10.5;
    test.d = 15.6;
    strcpy(test.strBuf, "hell");
    test.n = 10;
    fun1((int *)&test);
    return 0;
}
```
```txt
main
1.������ջ
0019FF38  01 00 00 00  ....
0019FF3C  48 12 6A 00  H.j.
0019FF40  00 13 6A 00  ..j.

2.���ص�ַ��ջ
0019FF34  89 14 40 00  ..@.

3.����ջ��
0019FF30  70 FF 19 00  p...

4.������ջ
0019FF10  42 CC CC CC  B��.        // 42ת��10����66��ӦASCII��	B
0019FF14  00 00 28 41  ..(A
0019FF18  33 33 33 33  3333
0019FF1C  33 33 2F 40  33/@
0019FF20  68 65 6C 6C  hell        // hell
0019FF24  00 CC CC CC  .��.
0019FF28  0A 00 00 00  ....                // int 10
0019FF2C  CC CC CC CC  ����

5.����CPU����(/Zi �ȶ�����12�ֽ�)
0019FEC4  A0 13 40 00  ..@.
0019FEC8  A0 13 40 00  ..@.
0019FECC  00 30 37 00  .07.


fun1
1.������ջ
0019FEC0  10 FF 19 00  ....                   // main�����б���0019FF10  42 CC CC CC  B��.     // 42ת��10����66��ӦASCII��	B

2.���ص�ַ��ջ
0019FEBC  82 11 40 00  ..@.

3.����ջ��
0019FEB8  30 FF 19 00  0...

4.������ջ
0019FEB0  CD CC 5C 41  ��\A
0019FEB4  0A 00 00 00  ....          // int 10

5.����CPU����(/Zi �ȶ�����12�ֽ�)
0019FE64  30 FF 19 00  0...            // ջ��
0019FE68  A0 13 40 00  ..@.
0019FE6C  00 30 37 00  .07.


fun2
1.������ջ
0019FE60  0A 00 00 00  ....                // int 10

2.���ص�ַ��ջ
0019FE5C  FD 10 40 00  ..@.

3.����ջ��
0019FE58  B8 FE 19 00  ��..

4.������ջ
0019FE50  CD CC 64 41  ��dA
0019FE54  14 00 00 00  ....                  // int 20

5.����CPU����(/Zi �ȶ�����12�ֽ�)
0019FE04  B8 FE 19 00  ��..
0019FE08  A0 13 40 00  ..@.
0019FE0C  00 30 37 00  .07.


fun3
1.������ջ
0019FDFC  14 00 00 00  ....               // int 20
0019FE00  CD CC 64 41  ��dA

2.���ص�ַ��ջ
0019FDF8  A3 10 40 00  ..@.

3.����ջ��
0019FDF4  58 FE 19 00  X...

4.������ջ
0019FDEC  CD CC 74 41  ��tA
0019FDF0  1E 00 00 00  ....                // int 30

5.����CPU����(/Zi �ȶ�����12�ֽ�)
0019FDA0  58 FE 19 00  X...
0019FDA4  A0 13 40 00  ..@.
0019FDA8  00 30 37 00  .07.
```
#### ��
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>


#ifdef _DEBUG
#define malloc(n) _malloc_dbg(n, _NORMAL_BLOCK, __FILE__, __LINE__);
#endif


 /*
    δ��ʼ�������԰棩��CD CD�����ַ����͡�,������Ѳ�����ʼ������,����  ��FE FE ���еĲ���ϵͳ��DD DD�������ַ����ݡ����ߡ�������
 */


int main()
{
    char* psz = NULL; // 0x0012ff7c
    psz = (char*)malloc(10); // return heap address 0x00381000
    if(psz==NULL)
    {
        printf("get memory error");
    }
    memset(psz, 0, 10);
    strcpy(psz, "hello");

    int* pn1 = NULL;
    pn1 = (int*)malloc(10); // 0012FF78
    if(pn1==NULL)
    {
        printf("get memory error");
    }
    memset(pn1, 0, 10);
    *pn1 = 100;

    free(psz);
    free(pn1);

	return 0;
}
```
```txt
00380FE0  98 07 38 00 00 00 00 00 00 00 00 00 00 00 00 00  ..8.............
00380FF0  0A 00 00 00 01 00 00 00 28 00 00 00 FD FD FD FD  ........(.......
00381000  CD CD CD CD CD CD CD CD CD CD FD FD FD FD AD BA  ................         // psz = (char*)malloc(10);


00381028  E0 0F 38 00 00 00 00 00 00 00 00 00 00 00 00 00  ..8.............
00381038  0A 00 00 00 01 00 00 00 29 00 00 00 FD FD FD FD  ........).......
00381048  CD CD CD CD CD CD CD CD CD CD FD FD FD FD AD BA  ................         // pn1 = (int*)malloc(10);

```
#### �ļ���д
```c
// �ļ������ݺ��ڴ���������ͬ��bģʽ����������ָ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tagTest{
    int a;
    float b;
    double c;
    char d[20];
};

int main()
{
    struct tagTest test[] = {
        {1, 3.14f, 0.618, "Hello"},
        {2, 4.14f, 1.618, "Jack"},
        {3, 5.14f, 2.618, "jjyy"},
    };

    FILE* fp = NULL;

    fp = fopen("test.bin", "rb+");
    if (fp == NULL)
    {
        fp = fopen("test.bin", "wb+");
        if(fp == NULL)
        {
            exit(-1);
        }
    }

    if(fwrite(test, sizeof(test), 1, fp)!=1)
    // if(fwrite(test, sizeof(test[0]), 3, fp)!=3)
    {
        int nError = ferror(fp);
        exit(nError);
    }

    // commit data
    if(EOF == fflush(fp))
    {
        int nError = ferror(fp);
        exit(nError);
    }

    // rewrite data
    int nSize = sizeof(struct tagTest);
    fseek(fp, -nSize, SEEK_CUR);
    test[2].a = 6;
    if(fwrite(&test[2], sizeof(test[2]), 1, fp)!=1)
    {
        int nError = ferror(fp);
        exit(nError);
    }

    if(fp)
    {
        fclose(fp);
    }


    return 0;
}
```
#### ��������
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap1(int* px, int* py)
{
    printf("px=%p\n", px);
    int* pTemp = px;
    px = py;
    py = pTemp;
}

void swap2(int* px, int* py)
{
    int pTemp = *px;
    *px = *py;
    *py = pTemp;
}


int main()
{
    int a = 1;
    int b = 2;
    // swap1(&a, &b);
    swap2(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
```

### C++
#### ��������
```c++
#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    // cout.setf(ios_base::dec);
    cout << oct << a << endl; // 8����
    cout << dec << a << endl; // 10����
    cout << hex << a << endl; // 16����
    return 0;
}
```
#### ���캯����������, ���캯�����Դ���, ����������������, �����������ܴ���
#### �ջ�սṹ��ռ��1�ֽڿռ�
#### size_t Ϊ�޷�������



