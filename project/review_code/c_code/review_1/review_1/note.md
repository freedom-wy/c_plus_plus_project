#### windows下编译c程序
```txt
gcc main.c会生成main.exe
gcc main.c -o hello 会生成hello.exe
会经历4个步骤
预处理: 宏定义展开、头文件展开、条件编译等，同时将代码中的注释删除，这里不会检查语法。gcc -E hello.c -o hello.i
编译: 检查语法，将预处理后的文件编译生成汇编文件。gcc -S hello.i -o hello.s
汇编: 将汇编文件生成目标文件。gcc -c hello.s -o hello.o
链接: C语言写的程序是需要依赖各种库的，所以编译后还需要把库链接到最终的可执行程序中去。gcc hello.o -o main.exe
```
#### return
```txt
return 0 代表执行成功, return -1代表程序执行失败
```
#### 两种定义常量方法
```c
#include <stdio.h>

#define MAX 10

int main()
{
	const int a = 20;
	printf("常量MAX的值为: %d\n", MAX);
	printf("常量a的值为: %d\n", a);
	return 0;
}
```
#### sizeof返回数据类型的大小, 单位为字节
#### int 4字节, short 2字节, long 4字节, long long 8字节
#### putchar 输出一个字符, getchar获取一个字符
#### scanf获取用户输入
#### 前置递增为先递增后进行运算, 即10先加1, 然后进行乘法运算, 后置递增为先进行乘法运算后加一
#### 三目运算符
```c
int a = 1;
int b = 2;
int c = a > b ? 10 : 20;
printf("c的值为: %d\n", c);
```
#### switch的参数只能是整型变量
#### 数组就是在内存中连续的相同类型的变量空间, 同一个数组所有的成员都是相同的数据类型，同时所有的成员在内存中的地址是连续的
#### 定义数组时, 中括号中有数字则可以不初始化, 中括号中无数字则必须初始化
#### 字符串和字符数组
```c
// 字符数组
char c1[] = { 'h', 'e', 'l', 'l', 'o' };
// 字符串
char c2[] = { 'h', 'e', 'l', 'l', 'o' , '\0' };
// 字符串
char str[] = "abcd1234";
printf("字符数组为: %s\n", c1); // 有乱码
printf("字符串为: %s\n", c2); // 无乱码
printf("字符串为: %s\n", str); // 无乱码
```
```c
char str[100];
printf("请输入字符串: ");
scanf("%s", str); // 遇到空格结束, 如输入hello world, 仅会输出hello
printf("输入的字符串为: %s\n", str);
```
```c
char str[1024];
printf("请输入字符串: ");
fgets(str, sizeof(str), stdin);
printf("字符串为: %s\n", str);
printf("sizeof值为: %d\n", sizeof(str)); // 1024
printf("strlen值为: %d\n", strlen(str)); // 5
```
#### void* 万能指针和类型转换
```c
void* p = NULL;
int a = 10;
p = (void*)&a;
*((int*)p) = 100;
printf("a的值为: %d\n", a);
```
#### 常量指针和指针常量
```c
int a = 10;
int const *p1 = &a; // 常量指针, 修饰的是*p1 因此不能修改值，只能改指向

int b = 20;
int* const p2 = &b; // 指针常量, 修饰的是p2, 因此可以修改值，不能改指向
```
#### 数组名是数组的首元素地址
#### 数组访问
```c
int a[] = { 1, 2, 3, 4, 5 };
int len = sizeof(a) / sizeof(a[0]); // 求出元素个数
for (int i = 0; i < len; i++)
{
	/*printf("元素值为: %d\n", a[i]);*/
	printf("元素值为: %d\n", *(a + i));
}

int* p = a;
for (int i = 0; i < len; i++)
{
	/*p[i] = 2 * i;*/
	*(p + i) = 2 * i;
}

for (int i = 0; i < len; i++)
{
	printf("赋值后的值为: %d\n", p[i]);
}
```
#### 指针数组, 是数组, 数组的每个元素都是指针类型
#### 静态(static)局部变量, static局部变量值仅初始化一次
```c
void fun1()
{
	int i = 0;
	i++;
	printf("i的值为: %d\n", i);
}

void fun2()
{
	static int a = 0;
	a++;
	printf("a的值为: %d\n", a);
}

fun1(); // 1
fun1(); // 1
fun2(); // 1
fun2(); // 2
```
#### 全局变量 通过extern来声明
```c
// 在main.c文件中通过extern声明int aaa
extern int aaa;
// 在test1.c文件中给aaa变量赋值 int aaa = 1;
int aaa = 1;
// 在main文件中访问
printf("aaa的值为: %d\n", aaa);
```
```txt
允许在不同的函数中使用相同的变量名，它们代表不同的对象，分配不同的单元，互不干扰。
同一源文件中,允许全局变量和局部变量同名，在局部变量的作用域内，全局变量不起作用。
所有的函数默认都是全局的，意味着所有的函数都不能重名，但如果是staitc函数，那么作用域是文件级的，所以不同的文件static函数名是可以相同的。
```
#### 栈区和堆区
```txt
栈是一种先进后出的内存结构，由编译器自动分配释放，存放函数的参数值、返回值、局部变量等。在程序运行过程中实时加载和释放，因此，局部变量的生存周期为申请到释放该段栈空间。
堆是一个大容器，它的容量要远远大于栈，但没有栈那样先进后出的顺序。用于动态内存分配。堆在内存中位于BSS区和栈区之间。一般由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收。
```
#### 在堆区申请数据
```c
// 在堆区申请内存空间
int n;
int* array;
printf("请输入数组大小: ");
scanf("%d", &n);
getchar();
array = (int*)malloc(n * sizeof(int));
if (array == NULL)
{
	printf("内存空间申请失败\n");
	return -1;
}
// 将内存空间清零
memset(array, 0, n * sizeof(int));

// 给堆区申请的数组赋值
for (int i = 0; i < n; i++)
{
	array[i] = i;
}

for (int i = 0; i < n; i++)
{
	printf("数组的值为: %d\n", array[i]);
}
free(array);
```
#### 不要返回局部变量的地址
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
	printf("*p的值为: %d\n", *p);
	printf("*p的值为: %d\n", *p); // 报错
	printf("*p的值为: %d\n", *p); // 报错
	printf("*p的值为: %d\n", *p); // 报错 */
	int* p = NULL;
	p = func2();
	*p = 100;
	printf("*p的值为: %d\n", *p);
	printf("*p的值为: %d\n", *p);
	printf("*p的值为: %d\n", *p);
	return 0;
}
```
#### 可以返回局部变量的堆区地址
```c
int* func3()
{
	int* tmp = NULL;
	tmp = (int*)malloc(sizeof(int));
	*tmp = 100;
	return tmp;
}
```













