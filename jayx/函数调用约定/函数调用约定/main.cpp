#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;


// _tmain������tchar��, ������Ŀ���õ��ַ����ı�, խ�ֽ�main, ���ֽ�wmain
// ʵ�ʵ��õ�main����Ϊ
/*
1������Ϊunicode���ֽ�, ������-�߼�-��ڵ�wmainCRTStartup, �ڵ�����������ΪwmainCRTStartup
2������Ϊ���ֽ�, ������-�߼�-��ڵ�mainCRTStartup, �ڵ�����������ΪmainCRTStartup
Ĭ�ϲ��޸���ڵ㣬��ڵ㶼ΪmainCRTStartup
*/

// __cdecl ��C/C++��Ĭ�ϵ���Լ������ջ˳����ҵ���
// __stdcall ��windows apiĬ�ϵ���Լ����΢���WINAPI�����������Լ��, ��ջ˳��Ҳ�Ǵ��ҵ���
// __fastcall ����Ҫƽջ����ջ˳�������������������������ecx��edx,������������ջ

int add_func(int a, int b);

int add_func(int a, int b)
{
	// c++Ĭ�Ϻ������÷�ʽ__cdecl���ɵ��÷�ƽջ����main����ƽջ
	return a + b;
}

void test()
{
	// c++Ĭ�Ϻ������÷�ʽ__cdecl���ɵ��÷�ƽջ������û�в�������returnƽջ
	cout << "test" << endl;
}

int _tmain()
{
	// test();
	add_func(1, 2);
	// MessageBox(NULL, _T("��Ϣ��ı���"), _T("��Ϣ�������"), MB_YESNO);  // __stdcall�ɱ��������Լ�ջƽ��
	return 0;
}