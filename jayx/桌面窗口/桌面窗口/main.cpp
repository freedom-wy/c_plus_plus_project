#include <windows.h>
#include <tchar.h>


// ����������
LPCTSTR class_name = _T("������");
LPCTSTR title = _T("���ڱ���");


// ע�ᴰ���� ������
ATOM MyRegisterClass(HINSTANCE hInstance);

// �����ڹ��� ������
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ��ʼ������ ������
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

// ע�ᴰ���� ��ʵ��
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
	wc.lpszClassName = _T("������");
	wc.hIcon = 0;
	// ע�ᴰ����
	return RegisterClass(&wc);
}

// ��ʼ������ ��ʵ��
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// ��������
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
	// ��ʾ����
	ShowWindow(hWnd, nCmdShow);
	// ���´���
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
			// Ĭ�ϴ��ڹ��̣�����ϵͳĬ�Ϸ�������
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
	}
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
{
	// MessageBox(NULL, _T("��������"), _T("���ڱ���"), MB_OKCANCEL);
	// ע�ᴰ����
	MyRegisterClass(hInstance);
	// �������ڣ���ʾ���ڣ����´���
	if (!InitInstance(hInstance, nShowCmd))
	{
		return false;
	}

	// ��Ϣѭ��
	MSG msg;
	while (true)
	{
		GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


