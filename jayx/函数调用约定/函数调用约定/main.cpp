#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


// _tmain定义在tchar中, 根据项目设置的字符集改变, 窄字节main, 宽字节wmain
// 实际调用的main方法为
/*
1、设置为unicode宽字节, 链接器-高级-入口点wmainCRTStartup, 在调试器中逆向为wmainCRTStartup
2、设置为多字节, 链接器-高级-入口点mainCRTStartup, 在调试器中逆向为mainCRTStartup
默认不修改入口点，入口点都为mainCRTStartup
*/

// __cdecl 是C/C++的默认调用约定，入栈顺序从右到左
// __stdcall 是windows api默认调用约定，微软的WINAPI都是这个调用约定, 入栈顺序也是从右到左

int add_func(int a, int b);

int add_func(int a, int b)
{
	return a + b;
}

int _tmain()
{
	add_func(1, 2);
	MessageBox(NULL, _T("消息框的标题"), _T("消息框的内容"), MB_YESNO);
	return 0;
}