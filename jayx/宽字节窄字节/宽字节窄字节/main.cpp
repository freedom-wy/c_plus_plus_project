#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;


// 1个字节 窄字节 char CHAR
// 2个字节 宽字节 wchar_t WCHAR

void test1()
{
	// 窄字节
	char s1 = 'a'; //1
	char s2 = 'b'; //1
	char s3 = '你'; //1

	// windows下的char
	CHAR w1 = 'a';  //1
	CHAR w2 = 'b';  //1
	CHAR w3 = '你';  //1

	// 宽字节
	wchar_t t1 = 'a'; //2
	wchar_t t2 = 'b'; //2
	wchar_t t3 = '你'; //2

	// windows下的wchar_t
	WCHAR r1 = 'a'; //2
	WCHAR r2 = 'b'; //2
	WCHAR r3 = '你'; //2
	// 与项目设置宽窄字节无关

	// TCHAR 通用类型
	TCHAR ts1 = 'a';
	TCHAR ts2 = 'b';
	TCHAR ts3 = '你';
	// 与项目设置宽窄字节有关，多字节1个字符, unicode2个字符



	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
	cout << sizeof(s3) << endl;

	cout << sizeof(w1) << endl;
	cout << sizeof(w2) << endl;
	cout << sizeof(w3) << endl;

	cout << sizeof(t1) << endl;
	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;

	cout << sizeof(r1) << endl;
	cout << sizeof(r2) << endl;
	cout << sizeof(r3) << endl;

	cout << sizeof(ts1) << endl;
	cout << sizeof(ts2) << endl;
	cout << sizeof(ts3) << endl;

	// 字符串
	// 窄字节使用strlen, 宽字节使用wcslen, 通用类型使用_tcslen
	const char* str1 = "abc"; // 4
	const wchar_t* str2 = L"abc"; // 4
	const TCHAR* str3 = _T("abc"); // 4

	cout << strlen(str1) << endl;
	cout << wcslen(str2) << endl;
	cout << _tcslen(str3) << endl;

	// 计算字符串占用空间大小
	cout << (strlen(str1) + 1) * sizeof(char) << endl;
	cout << (wcslen(str2) + 1) * sizeof(wchar_t) << endl;
	cout << (_tcslen(str3) + 1) * sizeof(TCHAR) << endl;
}




int main()
{
	test1();
	return 0;
}