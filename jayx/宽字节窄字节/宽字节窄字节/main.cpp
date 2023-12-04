#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
using namespace std;


// 1个字节 窄字节 char CHAR
// 2个字节 宽字节 wchar_t WCHAR

void test1()
{
	// 窄字节
	char s1 = 'a';
	char s2 = '你'; // cout 无法输出

	cout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
}

void test2()
{
	// windows下的窄字节
	CHAR s1 = 'a';
	CHAR s2 = '你';
	cout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
}

void testT()
{
	// 根据项目设置自动切换
#ifdef _UNICODE
	wcout.imbue(locale("chs"));
	TCHAR s1 = _T('a');
	TCHAR s2 = _T('你');
	wcout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
#else
	TCHAR s1 = _T('a');
	TCHAR s2 = _T('你');
	cout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
#endif
}

void test3()
{
	// 宽字节
	wcout.imbue(locale("chs"));
	wchar_t s1 = L'a';
	wchar_t s2 = L'你';
	wcout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
}

void test4()
{
	// 宽字节
	wcout.imbue(locale("chs")); // 必须设置中文语言环境, 和使用wcout输出
	WCHAR s1 = L'A'; // 在内存中是16进制的41, ascii表中10进制的65
	WCHAR s2 = L'你';
	wcout << "s1的值为: " << s1 <<
		", s1的大小为: " << sizeof(s1) <<
		", s2的值为: " << s2 <<
		", s2的大小为: " << sizeof(s2) << endl;
}

void test5()
{
	// 宽字节和窄字节字符串
	const char* str1 = "abc"; // 3
	const wchar_t* str2 = L"abc"; // 3

	cout << strlen(str1) << endl;
	cout << wcslen(str2) << endl;


	// 计算字符串占用空间大小
	cout << (strlen(str1) + 1) * sizeof(char) << endl; // 4
	cout << (wcslen(str2) + 1) * sizeof(wchar_t) << endl; // 8

	const TCHAR* str3 = _T("abc"); // 3
	cout << _tcslen(str3) << endl;
	cout << (_tcslen(str3) + 1) * sizeof(TCHAR) << endl; // 根据项目设置变化 4或8
}



int main()
{
	// test1();
	// test2();
	testT();
	// test3();
	// test4();
	return 0;
}