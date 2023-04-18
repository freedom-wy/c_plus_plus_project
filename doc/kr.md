### C语言
#### 无符号整数
```txt
无符号整数占4个字节, 由8个16进制数组成，当无符号整型不足32位时，用0来填充高位
```
#### 有符号整数
```txt
有符号整数中用来表示符号的是最高位, 即符号位, 最高位为0表示正数, 最高位为1表示负数, 有符号整数都是以补码形式存储的。
```
#### 补码
```txt
负数在内存中都是以补码的形式存放的
-3
原码 10000000 00000000 00000000 00000011
反码 11111111 11111111 11111111 11111100
补码 11111111 11111111 11111111 11111101
16进制  FFFFFFFD

3
原码 00000000 00000000 00000000 00000011
反码 00000000 00000000 00000000 00000011
补码 00000000 00000000 00000000 00000011
16进制  00000003

```
#### 浮点数
```txt
float类型在内存中占4个字节, 最高位用于表示符号, 在剩余31位中, 从左向右取8位表示指数, 其余表示尾数
12.25f转换为二进制数1100.01   小数部分乘以2    0.25*2=0.5计为0, 0.5*2=1 计为1
移位 小数点向左移动, 移动为1.10001, 共移动了3次
符号位 0
指数位 3+127=130转换为二进制为10000010
尾数位 10001 00000000000000000000000
拼接 0100 0001 0100 0100 0000 0000 0000 0000 0000 0 转成16进制41440000, 小尾 00004441

895.75转换为二进制数为1101111111.11
移位 1.10111111111, 移动了9次
符号位 0
指数位 9+127=136 转换为二进制为10001000
尾数位 10111111111000000000000
拼接 0100 0100 0101 1111 1111 0000 0000 0000  转换成16进制 445ff000, 小尾 00f05f44

-0.125f转换为二进制为 0.125*2计为0 0.25*2计为0 0.5*2计为1 结果为0.001
移位1.0 向右移动了3位
符号位 1
指数位 127-3 转换为二进制位 01111100
尾数位 00000000000000000000000
拼接 1011 1110 0000  0000 0000 0000 0000 0000 转换成16进制 BE 00 00 00 小尾 000000BE
```
#### 
```txt
每一个函数都在栈中有一块空间
一、按照调用约定传参, 调用约定: 1、参数的传递方向, 参数的存储媒介, 谁负责平衡参数(释放参数空间), 返回值的处理
约定有三类:
1、__cdecl: 默认约定, 从右向左传参, 参数通过栈传递, 调用方负责清理参数空间(支持不定参数)
2、__fastcall: 从右向左传参, 左数前两个参数通过处理器存放, 其余参数通过栈传递, 被调方负责清理参数空间(支持不定参数)
3、__stdcall: 微软定义的, 从右向左传参, 参数通过栈传递, 被调方负责清理参数空间(不支持不定参数)

二、在栈顶保存返回地址, 在内存中,可以存放多个函数的栈空间，被调用函数的栈空间在调用函数栈空间上面, 保存的是栈底数据
三、保存调用方的栈信息, 用于执行完被调用函数后返回调用函数
四、更新栈位置(在处理器中)到被调用方栈底处
五、在栈内开辟局部变量的空间
五.一、编译选项有/Zi+/Od, 则填充局部变量空间为0xcc
六、保存处理器环境
七、执行函数体
八、恢复处理器环境
九、释放局部变量空间
十、恢复栈信息到调用方
十一.一、取出返回地址并按此做流程更新, 抵达新地址后由调用方清理参数, __cdecl
十一.二、取出返回地址并清理参数，然后按返回地址做流程更新, __stdcall, __fastcall
```
#### 数组求地址公式 十六进制计算
```txt
Int i[5]，已知i的首地址是0012FF6C，求i[4]
0012FF6C+4×4= 0012FF6C+10（十进制是16）= 0012FF7C

ary:0x0019ff1c
int n=8
ary[3]=0x0019FF28
ary[n]=0x0019FF3C
ary[n-5]=0x0019FF28
ary[5-n]=0x0019FF10


多维数组求地址
先算外层数组地址
再算内层数组地址

int arr[M][N];
求 arr[1][2]的地址
数组首地址+sizeof(type[N])*1+sizeof(type)*2
```
#### 字符串
```txt
ASCII表示字符 char ch1 = 'a'; // 一个字节
UNICODE表示字符 short int ch2 = L'a'; // 两个字节

char szBuf[] = "hello"; // 用strcpy拷贝
unsigned short int wszBuf[] = L"Hello"; // 用wcscpy拷贝

printf("%s\n", szBuf);
wprintf(l"%s\n", wszBuf);

```
#### 全局变量
```txt
全局变量在link阶段写入可执行文件
00400000 可执行文件装载在内存中的位置叫模块基址
```
#### 静态全局变量
```txt
受语法约束的全局变量, 在当前文件中有效
```
#### 静态局部变量
```txt
受语法约束的全局变量, 在当前函数中有效
```
```c
#include <iostream>
using namespace std;


// 在c++中，无法在内存中观测到静态局部变量数据，在c中可以

// 在C++中可以通过这种方法对常量进行初始化, 在C中不行
int getInt()
{
    return 1;
}

int g_a = getInt();
// cout << "全局变量值为: " << g_a << endl;
// printf("全局变量值为: %d\n", g_a);


void foo()
{
    static char str[] = "hello world";
    // cout << "foo中静态变量值为: " << str << endl;
    printf("foo中静态变量为: %s\n", str);
}


int main()
{
    foo();
    static int a = 100;
    // cout << "main中静态变量值为: " << a << endl;
    printf("foo中静态变量为: %d\n", a);
    return 0;
}
```
```c
// 在C中可观测静态局部变量数据, 在C++中无法观测
#include <stdio.h>


static char g_szBuf[] = "Hello CR40!";

extern void foo();

// 在C语言中无法通过该方法给全局变量赋值
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
// 静态变量仅初始化一次，在内存中有标识，可修改表示，让静态变量重复赋值
#include <stdio.h>

void foo(int num)
{
    static int val = num;
    printf("值为: %d\n", val);
    printf("地址为: %p\n", &val);
    printf("地址为: %p\n", &(&val)[-1]);
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
#### 宏定义
```txt
宏定义如#define 语句结束无分号
有参宏也叫表达式宏 #define GET_AREA(r) ((r)*(r)*3.14)
```
```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 解决在6.0中重复定义for循环中变量冲突问题
#define for if(1)for
// 转换后, 通过if语句包裹
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
    // 在visual c++6.0中是局部作用域
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

#define while if // 将while替换为if
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
#### 通过宏解决重复包含问题
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

// 无参数宏
#define IN scanf
#define OUT printf

// 带参数宏
#define PI 3.1415926f
#define S(r) PI*(r)*(r)

// 符号常量宏
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
    // __FILE__ 文件名称 __LINE__ 文件行数
    // 编译预处理, 在debug参数中定义
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
#### 指针
```txt
指针是特殊的地址，地址不一定是指针
指针只保存了存放数据的首地址，而没有指明该在哪里结束，因此类型即为告诉指针在哪里结束
指针保存的是地址，因此无论什么类型的指针，32位程序占用4字节，64位程序占用8字节

++p得到指针变量
p++得到指针常量
```
```c
char ary[5] = {'a', 'b', 'c', 'd', 'e'};
    
int* p1 = NULL;
char* p2 = NULL;
short* p3 = NULL;

p1 = (int*)ary;
p2 = (char*)ary;
p3 = (short*)ary;

p1++; // 移动4个字节
p2++; // 移动1个字节
p3++; // 移动2个字节
```
```txt
修改WRES，打开二进制文件后，找到rdata，两行半，将40的4转换为二进制0100，修改为1100，即为C0，则常量可修改
```
#### 指针函数
```txt
用于保存函数首地址的指针变量被称为函数指针
不能返回局部变量和参数地址
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testAdd(int a, int b)
{
    return a+b;
}

// 通过typedef定义新的类型
typedef int(*PFNTESTADD)(int, int);

int main()
{
    PFNTESTADD pfntestAdd = NULL;
    //int(*p)(int, int)=NULL; // 定义一个函数指针
    pfntestAdd = testAdd; // 指针变量赋值
    int c = (*pfntestAdd)(1, 2); // 指针函数调用和传参
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

// 通过typedef定义新的类型
typedef int(*PFNTESTADD)(int, int);*/


void SortA(int aryCard[], int nCount)
{
    printf("A排序方法\n");
}

void SortB(int aryCard[], int nCount)
{
    printf("B排序方法\n");
}

// 通过typedef定义函数指针别名
typedef void (*PFNSORT)(int [], int);

void PlayCard(int aryCard[], int nCount, PFNSORT pfnSort=NULL)
{
    // 洗牌
    pfnSort(aryCard, nCount);
}



int main()
{
    /*PFNTESTADD pfntestAdd = NULL;
    //int(*p)(int, int)=NULL; // 定义一个函数指针
    pfntestAdd = testAdd; // 指针变量赋值
    int c = pfntestAdd(1, 2); // 指针函数调用和传参
    printf("c=%d\n", c);*/
    
    int card[54];
    PlayCard(card, 54, SortA);
    return 0;
}
```
#### 指针数组
```txt
数组名是数组第0个元素类型的地址常量
如果数组内数据为指针，则数组名是指针类型的地址常量，即指针的地址，用**
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MySwap(int* p1, int* p2)
{
    // 无法交换
    /*int* pTmp = p1;
    p1 = p2;
    p2 = pTmp;*/
    // 必须要有间接访问才会有交换
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    // 地址传递大坑
    int a = 1;
    int b = 2;
    MySwap(&a, &b);
    printf("交换后a=%d, b=%d\n", a, b);
    return 0;
}
```
#### 结构体
```txt
设编译器对齐方式为Zp，默认为8
设成员变量到结构体之间的地址差为member offset
member必须满足	member offset % min(Zp,sizeof(member type)) == 0;

设结构体自身对齐为StructAlign
stryctAlign必须满足
StructAlign = max(sizeof(member1 type),sizeof(member2 type)···,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(结构体变量)必须满足
sizeof(结构体变量)%structAlign == 0;


结构体寻址公式：结构体首地址+成员偏移量
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
和offsetof关键字展开后的结果相同。
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
设编译器对齐方式为Zp，默认为8
设成员变量到结构体之间的地址差为member offset
member必须满足	member offset % min(Zp,sizeof(member type)) == 0;

设结构体自身对齐为StructAlign
stryctAlign必须满足
StructAlign = max(sizeof(member1 type),sizeof(member2 type)···,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(结构体变量)必须满足
sizeof(结构体变量)%structAlign == 0;


结构体寻址公式：结构体首地址+成员偏移量
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
和offsetof关键字展开后的结果相同。
*/


struct tagDateOfBirth // 自身对其为4
{
    int nYear; // +0
    short int wMonth; // +4
    char cDay; // +6
}; // 7 % 4 == 0 因此sizeof为8

// 定义结构体
struct tagStuInfo 
{
    char szName[5]; // +0 // 8 % min(8,sizeof(char)) == 0;
    float fHeight; // +8
    short int wScore; // +12
    int nAge; // +16
    char cGender; // +20
    double dblWeight; // +24
    struct tagDateOfBirth dob; // 类型为StructAlign为4 // +32
}; // 40 % 8 ==0 因此sizeof 为40

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
#### 共用体 枚举
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
#### 函数嵌套调用
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
1.参数入栈
0019FF38  01 00 00 00  ....
0019FF3C  48 12 6A 00  H.j.
0019FF40  00 13 6A 00  ..j.

2.返回地址入栈
0019FF34  89 14 40 00  ..@.

3.保存栈底
0019FF30  70 FF 19 00  p...

4.变量入栈
0019FF10  42 CC CC CC  B烫.        // 42转成10进制66对应ASCII表	B
0019FF14  00 00 28 41  ..(A
0019FF18  33 33 33 33  3333
0019FF1C  33 33 2F 40  33/@
0019FF20  68 65 6C 6C  hell        // hell
0019FF24  00 CC CC CC  .烫.
0019FF28  0A 00 00 00  ....                // int 10
0019FF2C  CC CC CC CC  烫烫

5.保存CPU环境(/Zi 稳定保存12字节)
0019FEC4  A0 13 40 00  ..@.
0019FEC8  A0 13 40 00  ..@.
0019FECC  00 30 37 00  .07.


fun1
1.参数入栈
0019FEC0  10 FF 19 00  ....                   // main函数中变量0019FF10  42 CC CC CC  B烫.     // 42转成10进制66对应ASCII表	B

2.返回地址入栈
0019FEBC  82 11 40 00  ..@.

3.保存栈底
0019FEB8  30 FF 19 00  0...

4.变量入栈
0019FEB0  CD CC 5C 41  吞\A
0019FEB4  0A 00 00 00  ....          // int 10

5.保存CPU环境(/Zi 稳定保存12字节)
0019FE64  30 FF 19 00  0...            // 栈顶
0019FE68  A0 13 40 00  ..@.
0019FE6C  00 30 37 00  .07.


fun2
1.参数入栈
0019FE60  0A 00 00 00  ....                // int 10

2.返回地址入栈
0019FE5C  FD 10 40 00  ..@.

3.保存栈底
0019FE58  B8 FE 19 00  羹..

4.变量入栈
0019FE50  CD CC 64 41  吞dA
0019FE54  14 00 00 00  ....                  // int 20

5.保存CPU环境(/Zi 稳定保存12字节)
0019FE04  B8 FE 19 00  羹..
0019FE08  A0 13 40 00  ..@.
0019FE0C  00 30 37 00  .07.


fun3
1.参数入栈
0019FDFC  14 00 00 00  ....               // int 20
0019FE00  CD CC 64 41  吞dA

2.返回地址入栈
0019FDF8  A3 10 40 00  ..@.

3.保存栈底
0019FDF4  58 FE 19 00  X...

4.变量入栈
0019FDEC  CD CC 74 41  吞tA
0019FDF0  1E 00 00 00  ....                // int 30

5.保存CPU环境(/Zi 稳定保存12字节)
0019FDA0  58 FE 19 00  X...
0019FDA4  A0 13 40 00  ..@.
0019FDA8  00 30 37 00  .07.
```
#### 堆
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>


#ifdef _DEBUG
#define malloc(n) _malloc_dbg(n, _NORMAL_BLOCK, __FILE__, __LINE__);
#endif


 /*
    未初始化（调试版）：CD CD中文字符“屯”,发布版堆不做初始化动作,空闲  ：FE FE （有的操作系统是DD DD）中文字符“葺”或者“铪”。
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
#### 文件读写
```c
// 文件中数据和内存中数据相同，b模式，可灵活操作指针
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
#### 变量交换
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
#### 输入和输出
```c++
#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    // cout.setf(ios_base::dec);
    cout << oct << a << endl; // 8进制
    cout << dec << a << endl; // 10进制
    cout << hex << a << endl; // 16进制
    return 0;
}
```
#### 构造函数可以重载, 构造函数可以传参, 析构函数不能重载, 析构函数不能传参
#### 空或空结构体占用1字节空间
#### size_t 为无符号整形



