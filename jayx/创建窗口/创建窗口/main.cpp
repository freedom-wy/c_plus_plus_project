#include <windows.h>
#include <tchar.h>

// 窗口类名称
LPCTSTR class_name = _T("类名称");
LPCTSTR title = _T("窗口标题");


// 注册窗口类 类声明
ATOM MyRegisterClass(HINSTANCE hInstance);

// 主窗口过程 类声明
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 初始化窗口 类声明
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

// 注册窗口类 类实现
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = 0;
	wc.lpszClassName = class_name;
	wc.hIcon = 0;
	// 注册窗口类
	return RegisterClass(&wc);
}

// 初始化窗口 类实现
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// 创建窗口
	HWND hWnd = CreateWindow(
		class_name,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		500,
		500,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		return false;
	}
	// 显示窗口
	ShowWindow(hWnd, nCmdShow);
	// 更新窗口
	UpdateWindow(hWnd);
	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
	{
		// 默认窗口过程，交给系统默认方法处理
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	}
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
{
	// MessageBox(NULL, _T("窗口内容"), _T("窗口标题"), MB_OKCANCEL);
	// 注册窗口类
	MyRegisterClass(hInstance);
	// 创建窗口，显示窗口，更新窗口
	if (!InitInstance(hInstance, nShowCmd))
	{
		return false;
	}

	// 消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}