#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;


// 1���ֽ� խ�ֽ� char CHAR
// 2���ֽ� ���ֽ� wchar_t WCHAR

void test1()
{
	// խ�ֽ�
	char s1 = 'a'; //1
	char s2 = 'b'; //1
	char s3 = '��'; //1

	// windows�µ�char
	CHAR w1 = 'a';  //1
	CHAR w2 = 'b';  //1
	CHAR w3 = '��';  //1

	// ���ֽ�
	wchar_t t1 = 'a'; //2
	wchar_t t2 = 'b'; //2
	wchar_t t3 = '��'; //2

	// windows�µ�wchar_t
	WCHAR r1 = 'a'; //2
	WCHAR r2 = 'b'; //2
	WCHAR r3 = '��'; //2
	// ����Ŀ���ÿ�խ�ֽ��޹�

	// TCHAR ͨ������
	TCHAR ts1 = 'a';
	TCHAR ts2 = 'b';
	TCHAR ts3 = '��';
	// ����Ŀ���ÿ�խ�ֽ��йأ����ֽ�1���ַ�, unicode2���ַ�



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

	// �ַ���
	// խ�ֽ�ʹ��strlen, ���ֽ�ʹ��wcslen, ͨ������ʹ��_tcslen
	const char* str1 = "abc"; // 4
	const wchar_t* str2 = L"abc"; // 4
	const TCHAR* str3 = _T("abc"); // 4

	cout << strlen(str1) << endl;
	cout << wcslen(str2) << endl;
	cout << _tcslen(str3) << endl;

	// �����ַ���ռ�ÿռ��С
	cout << (strlen(str1) + 1) * sizeof(char) << endl;
	cout << (wcslen(str2) + 1) * sizeof(wchar_t) << endl;
	cout << (_tcslen(str3) + 1) * sizeof(TCHAR) << endl;
}




int main()
{
	test1();
	return 0;
}