#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


// _tmain������tchar��, ������Ŀ���õ��ַ����ı�, խ�ֽ�main, ���ֽ�wmain
// ʵ�ʵ��õ�main����Ϊ
/*
1������Ϊunicode���ֽ�, ������-�߼�-��ڵ�wmainCRTStartup, �ڵ�����������ΪwmainCRTStartup
2������Ϊ���ֽ�, ������-�߼�-��ڵ�mainCRTStartup, �ڵ�����������ΪmainCRTStartup
Ĭ�ϲ��޸���ڵ㣬��ڵ㶼ΪmainCRTStartup
*/

// __cdecl ��C/C++��Ĭ�ϵ���Լ������ջ˳����ҵ���
// __stdcall ��windows apiĬ�ϵ���Լ����΢���WINAPI�����������Լ��, ��ջ˳��Ҳ�Ǵ��ҵ���

int add_func(int a, int b);

int add_func(int a, int b)
{
	return a + b;
}

int _tmain()
{
	add_func(1, 2);
	MessageBox(NULL, _T("��Ϣ��ı���"), _T("��Ϣ�������"), MB_YESNO);
	return 0;
}