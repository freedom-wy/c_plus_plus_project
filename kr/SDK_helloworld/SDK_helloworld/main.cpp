#include <Windows.h>
#include <iostream>
using namespace std;

// 项目->XXX属性->配置属性->高级->字符集，由使用Unicode字符集改为使用多字节字符集。

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    MessageBox(NULL, "hello world", "sdk", MB_OK);
    return 0;
}