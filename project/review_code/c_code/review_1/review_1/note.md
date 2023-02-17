#### windows�±���c����
```txt
gcc main.c������main.exe
gcc main.c -o hello ������hello.exe
�ᾭ��4������
Ԥ����: �궨��չ����ͷ�ļ�չ������������ȣ�ͬʱ�������е�ע��ɾ�������ﲻ�����﷨��gcc -E hello.c -o hello.i
����: ����﷨����Ԥ�������ļ��������ɻ���ļ���gcc -S hello.i -o hello.s
���: ������ļ�����Ŀ���ļ���gcc -c hello.s -o hello.o
����: C����д�ĳ�������Ҫ�������ֿ�ģ����Ա������Ҫ�ѿ����ӵ����յĿ�ִ�г�����ȥ��gcc hello.o -o main.exe
```
#### return
```txt
return 0 ����ִ�гɹ�, return -1�������ִ��ʧ��
```
#### ���ֶ��峣������
```c
#include <stdio.h>

#define MAX 10

int main()
{
	const int a = 20;
	printf("����MAX��ֵΪ: %d\n", MAX);
	printf("����a��ֵΪ: %d\n", a);
	return 0;
}
```
#### sizeof�����������͵Ĵ�С, ��λΪ�ֽ�
#### int 4�ֽ�, short 2�ֽ�, long 4�ֽ�, long long 8�ֽ�
#### putchar ���һ���ַ�, getchar��ȡһ���ַ�
#### scanf��ȡ�û�����
#### ǰ�õ���Ϊ�ȵ������������, ��10�ȼ�1, Ȼ����г˷�����, ���õ���Ϊ�Ƚ��г˷�������һ
#### ��Ŀ�����
```c
int a = 1;
int b = 2;
int c = a > b ? 10 : 20;
printf("c��ֵΪ: %d\n", c);
```
#### switch�Ĳ���ֻ�������ͱ���
#### ����������ڴ�����������ͬ���͵ı����ռ�, ͬһ���������еĳ�Ա������ͬ���������ͣ�ͬʱ���еĳ�Ա���ڴ��еĵ�ַ��������
#### ��������ʱ, ������������������Բ���ʼ��, ��������������������ʼ��
#### �ַ������ַ�����
```c
// �ַ�����
char c1[] = { 'h', 'e', 'l', 'l', 'o' };
// �ַ���
char c2[] = { 'h', 'e', 'l', 'l', 'o' , '\0' };
// �ַ���
char str[] = "abcd1234";
printf("�ַ�����Ϊ: %s\n", c1); // ������
printf("�ַ���Ϊ: %s\n", c2); // ������
printf("�ַ���Ϊ: %s\n", str); // ������
```
```c
char str[100];
printf("�������ַ���: ");
scanf("%s", str); // �����ո����, ������hello world, �������hello
printf("������ַ���Ϊ: %s\n", str);
```
```c
char str[1024];
printf("�������ַ���: ");
fgets(str, sizeof(str), stdin);
printf("�ַ���Ϊ: %s\n", str);
printf("sizeofֵΪ: %d\n", sizeof(str)); // 1024
printf("strlenֵΪ: %d\n", strlen(str)); // 5
```
#### void* ����ָ�������ת��
```c
void* p = NULL;
int a = 10;
p = (void*)&a;
*((int*)p) = 100;
printf("a��ֵΪ: %d\n", a);
```
#### ����ָ���ָ�볣��
```c
int a = 10;
int const *p1 = &a; // ����ָ��, ���ε���*p1 ��˲����޸�ֵ��ֻ�ܸ�ָ��

int b = 20;
int* const p2 = &b; // ָ�볣��, ���ε���p2, ��˿����޸�ֵ�����ܸ�ָ��
```
#### ���������������Ԫ�ص�ַ
#### �������
```c
int a[] = { 1, 2, 3, 4, 5 };
int len = sizeof(a) / sizeof(a[0]); // ���Ԫ�ظ���
for (int i = 0; i < len; i++)
{
	/*printf("Ԫ��ֵΪ: %d\n", a[i]);*/
	printf("Ԫ��ֵΪ: %d\n", *(a + i));
}

int* p = a;
for (int i = 0; i < len; i++)
{
	/*p[i] = 2 * i;*/
	*(p + i) = 2 * i;
}

for (int i = 0; i < len; i++)
{
	printf("��ֵ���ֵΪ: %d\n", p[i]);
}
```
#### ָ������, ������, �����ÿ��Ԫ�ض���ָ������
#### ��̬(static)�ֲ�����, static�ֲ�����ֵ����ʼ��һ��
```c
void fun1()
{
	int i = 0;
	i++;
	printf("i��ֵΪ: %d\n", i);
}

void fun2()
{
	static int a = 0;
	a++;
	printf("a��ֵΪ: %d\n", a);
}

fun1(); // 1
fun1(); // 1
fun2(); // 1
fun2(); // 2
```
#### ȫ�ֱ��� ͨ��extern������
```c
// ��main.c�ļ���ͨ��extern����int aaa
extern int aaa;
// ��test1.c�ļ��и�aaa������ֵ int aaa = 1;
int aaa = 1;
// ��main�ļ��з���
printf("aaa��ֵΪ: %d\n", aaa);
```
```txt
�����ڲ�ͬ�ĺ�����ʹ����ͬ�ı����������Ǵ���ͬ�Ķ��󣬷��䲻ͬ�ĵ�Ԫ���������š�
ͬһԴ�ļ���,����ȫ�ֱ����;ֲ�����ͬ�����ھֲ��������������ڣ�ȫ�ֱ����������á�
���еĺ���Ĭ�϶���ȫ�ֵģ���ζ�����еĺ����������������������staitc��������ô���������ļ����ģ����Բ�ͬ���ļ�static�������ǿ�����ͬ�ġ�
```
#### ջ���Ͷ���
```txt
ջ��һ���Ƚ�������ڴ�ṹ���ɱ������Զ������ͷţ���ź����Ĳ���ֵ������ֵ���ֲ������ȡ��ڳ������й�����ʵʱ���غ��ͷţ���ˣ��ֲ���������������Ϊ���뵽�ͷŸö�ջ�ռ䡣
����һ������������������ҪԶԶ����ջ����û��ջ�����Ƚ������˳�����ڶ�̬�ڴ���䡣�����ڴ���λ��BSS����ջ��֮�䡣һ���ɳ���Ա������ͷţ�������Ա���ͷţ��������ʱ�ɲ���ϵͳ���ա�
```
#### �ڶ�����������
```c
// �ڶ��������ڴ�ռ�
int n;
int* array;
printf("�����������С: ");
scanf("%d", &n);
getchar();
array = (int*)malloc(n * sizeof(int));
if (array == NULL)
{
	printf("�ڴ�ռ�����ʧ��\n");
	return -1;
}
// ���ڴ�ռ�����
memset(array, 0, n * sizeof(int));

// ��������������鸳ֵ
for (int i = 0; i < n; i++)
{
	array[i] = i;
}

for (int i = 0; i < n; i++)
{
	printf("�����ֵΪ: %d\n", array[i]);
}
free(array);
```
#### ��Ҫ���ؾֲ������ĵ�ַ
```c
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

int main()
{
	/*int* p = NULL;
	p = func1();
	*p = 100;
	printf("*p��ֵΪ: %d\n", *p);
	printf("*p��ֵΪ: %d\n", *p); // ����
	printf("*p��ֵΪ: %d\n", *p); // ����
	printf("*p��ֵΪ: %d\n", *p); // ���� */
	int* p = NULL;
	p = func2();
	*p = 100;
	printf("*p��ֵΪ: %d\n", *p);
	printf("*p��ֵΪ: %d\n", *p);
	printf("*p��ֵΪ: %d\n", *p);
	return 0;
}
```
#### ���Է��ؾֲ������Ķ�����ַ
```c
int* func3()
{
	int* tmp = NULL;
	tmp = (int*)malloc(sizeof(int));
	*tmp = 100;
	return tmp;
}
```













