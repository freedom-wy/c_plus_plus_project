#include <wchar.h>
#include <Locale.h>
#include <stdio.h>
#include <stdlib.h>


void test1()
{
	char a = 'a';
	char str[] = "abc";
	printf("字符为: %c, 字符串为: %s\n", a, str);
	printf("字符大小为: %d, 字符串大小为: %d\n", sizeof(a), sizeof(str));
}

void test2()
{
	setlocale(LC_ALL, "chs");
	wchar_t a = L'a';
	wchar_t str[] = L"abc";
	wchar_t s = L'中';
	wchar_t s1[] = L"中国人";
	wprintf(L"char: %lc, str: %ls\n", a, str);
	wprintf(L"chinese: %lc, %ls\n",s, s1);
	printf("字符大小为: %d, 字符串大小为: %d\n", sizeof(a), sizeof(str));
}


int main()
{

	test1();
	test2();
	return 0;
}
