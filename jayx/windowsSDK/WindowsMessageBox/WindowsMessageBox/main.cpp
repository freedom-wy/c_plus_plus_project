#include <Windows.h>
#include <tchar.h>



int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, TCHAR* pCmdLine, int nCmdShow);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, TCHAR* pCmdLine, int nCmdShow)
{
	MessageBox(NULL, _T("消息框的内容"), _T("消息框的标题"), MB_YESNO);
	return 0;
}