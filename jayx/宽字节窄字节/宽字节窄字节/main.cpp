#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
using namespace std;


// 1���ֽ� խ�ֽ� char CHAR
// 2���ֽ� ���ֽ� wchar_t WCHAR

void test1()
{
	// խ�ֽ�
	char s1 = 'a';
	char s2 = '��'; // cout �޷����

	cout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
}

void test2()
{
	// windows�µ�խ�ֽ�
	CHAR s1 = 'a';
	CHAR s2 = '��';
	cout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
}

void testT()
{
	// ������Ŀ�����Զ��л�
#ifdef _UNICODE
	wcout.imbue(locale("chs"));
	TCHAR s1 = _T('a');
	TCHAR s2 = _T('��');
	wcout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
#else
	TCHAR s1 = _T('a');
	TCHAR s2 = _T('��');
	cout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
#endif
}

void test3()
{
	// ���ֽ�
	wcout.imbue(locale("chs"));
	wchar_t s1 = L'a';
	wchar_t s2 = L'��';
	wcout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
}

void test4()
{
	// ���ֽ�
	wcout.imbue(locale("chs")); // ���������������Ի���, ��ʹ��wcout���
	WCHAR s1 = L'A'; // ���ڴ�����16���Ƶ�41, ascii����10���Ƶ�65
	WCHAR s2 = L'��';
	wcout << "s1��ֵΪ: " << s1 <<
		", s1�Ĵ�СΪ: " << sizeof(s1) <<
		", s2��ֵΪ: " << s2 <<
		", s2�Ĵ�СΪ: " << sizeof(s2) << endl;
}

void test5()
{
	// ���ֽں�խ�ֽ��ַ���
	const char* str1 = "abc"; // 3
	const wchar_t* str2 = L"abc"; // 3

	cout << strlen(str1) << endl;
	cout << wcslen(str2) << endl;


	// �����ַ���ռ�ÿռ��С
	cout << (strlen(str1) + 1) * sizeof(char) << endl; // 4
	cout << (wcslen(str2) + 1) * sizeof(wchar_t) << endl; // 8

	const TCHAR* str3 = _T("abc"); // 3
	cout << _tcslen(str3) << endl;
	cout << (_tcslen(str3) + 1) * sizeof(TCHAR) << endl; // ������Ŀ���ñ仯 4��8
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