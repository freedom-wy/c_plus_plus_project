// 绘制图形.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "绘制图形.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
BOOL MyPaint(HDC hdc);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 500, 500, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            MyPaint(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// 绘制图形
BOOL MyPaint(HDC hdc)
{
    // 创建画笔
    HPEN hBluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
    // 选择画笔
    HGDIOBJ hBluePenObj1 = SelectObject(hdc, hBluePen);

    // 画线
    // 定义点
    POINT pt = { 0 };
    // 移动到起始位置
    MoveToEx(hdc, 100, 100, &pt);
    // 移动到目的位置
    LineTo(hdc, 100, 400);
    
    // 画矩形
    // Rectangle(hdc, 150, 100, 300, 200);

    //// 通过画刷填充矩形
    //HBRUSH hSolidBrush1 = CreateSolidBrush(RGB(0, 0, 255)); // 实心画刷
    //// 选择画刷
    //HGDIOBJ hSolidBrushObj1 = SelectObject(hdc, hSolidBrush1);

    // 带阴影的画刷
    HBRUSH hSolidBrush2 = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 255));
    HGDIOBJ hSolidBrushObj2 = SelectObject(hdc, hSolidBrush2);
    Rectangle(hdc, 150, 100, 300, 200);

    // 写字
    TextOut(hdc, 300, 300, L"hello", wcslen(L"hello"));

    // 文本框
    HFONT hFont = CreateFont(20, 10, 0, 0, 0, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, L"宋体");
    SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);
    RECT rect;
    SetRect(&rect, 30, 300, 400, 200);
    SetTextColor(hdc, RGB(255, 0, 255));
    DrawText(hdc, L"这是一个实例", -1, &rect, DT_NOCLIP);

    // 画圆
    Arc(hdc, 100, 200, 200, 100, 350, 350, 350, 350);

    // 画曲线
    POINT pi[4] = {
    10,120,
    180,300,
    300,180,
    120,10
    };
    PolyBezier(hdc, pi, 4);

    // 设置背景图
    HBITMAP hBitMap = (HBITMAP)LoadImage(NULL, L"bg.bmp", IMAGE_BITMAP, 500, 500, LR_LOADFROMFILE);
    HDC hMemoryDC = CreateCompatibleDC(hdc);
    HGDIOBJ hMemoryDCObj = SelectObject(hMemoryDC, hBitMap);
    BitBlt(hdc, 0, 0, 500, 500, hMemoryDC, 0, 0, SRCCOPY);

    // 删除画笔
    DeleteObject(hBluePenObj1);
    // DeleteObject(hSolidBrushObj1);
    DeleteObject(hSolidBrushObj2);
    DeleteObject(hFont);
    DeleteObject(hMemoryDCObj);
    return 0;
}
