#include <Windows.h>
#include <iostream>
using namespace std;

// ��Ŀ->XXX����->��������->�߼�->�ַ�������ʹ��Unicode�ַ�����Ϊʹ�ö��ֽ��ַ�����

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    MessageBox(NULL, "hello world", "sdk", MB_OK);
    return 0;
}