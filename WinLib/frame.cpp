#include "frame.h"

static Frame* globalFrame = NULL;  // 다른 파일에서는 사용할 수 없다.
// 전역함수로는 윈도 메시지 처리 함수가 있다.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: 
	
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_RBUTTONUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	case WM_SIZE:
	{
		RECT rect;
		GetClientRect(Hw, &rect);
		if (globalFrame) {
			if (globalFrame->tbar) {
				globalFrame->tbar->right_ = rect.right - rect.left;
			}
		}
		//globalFrame->processMessage(MyEvent(Msg, wParam, lParam));
	}

	case WM_MOUSEMOVE:
	{
		if (globalFrame) {
			//메시지 처리
			globalFrame->processMessage(MyEvent(Msg, wParam, lParam));
		}
		
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		if (globalFrame) {
			globalFrame->processMessage(MyEvent(Msg, wParam, lParam));
		}
		EndPaint(Hw, &ps);
	}
	break;
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame(std::wstring title, int width, int height) {
	
	//initialize();
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hwnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWIn", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hwnd_) throw 0;
	hdc_ = GetDC(hwnd_); //hdc 가져오기
	globalFrame = this;

	ShowWindow(hwnd_, SW_SHOW);
	UpdateWindow(hwnd_); 
	SetFocus(hwnd_);
}

Frame::Frame(std::wstring title) {
	Frame(title, 1000, 800);
	//globalFrame을 this로 설정
	globalFrame = this;

}

void Frame::run() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	
	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}