#include <Windows.h>
#include <iostream>
using namespace std;

// 项目->XXX属性->配置属性->高级->字符集，调整Unicode字符集和多字节字符集。

// 定义窗口类结构（WNDCLASS）->注册窗口类（RegisterClass）->创建窗口（CreateWindow）->显示窗口（ShowWindow）->更新窗口（UpdateWindow）->消息循环（GetMessage->TranslateMessage->DispatchMessage）

// 窗口过程回调函数声明
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    /*int code = MessageBox(NULL, L"hello world", L"sdk", MB_YESNO);
    if (code == IDYES)
    {
        MessageBox(NULL, L"确定", L"YES", MB_OK);
    }
    else if(code==IDNO)
    {
        MessageBox(NULL, L"取消", L"NO", MB_OK);
    }*/

    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd; // 窗口句柄
    MSG msg; // 消息
    WNDCLASS wndclass;

    // 定义窗口类结构
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = NULL;
    wndclass.hCursor = NULL;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    
    // 注册窗口类
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("这个程序需要在windowsNT中才能执行"), szAppName, MB_ICONERROR);
        return 0;
    }

    // 创建窗口
    hwnd = CreateWindow(
        szAppName,
        TEXT("我的窗口"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    // 更新窗口
    UpdateWindow(hwnd);

    // 获取消息队列
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("大家好，这是我的第一个窗口程序！"), -1, &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}