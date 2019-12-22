#pragma once
#include "Windows.h"
#include <string>
#include "MyEvent.h"
#include "ToolBar.h"
#include "Container.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame :public Container{
public:
	//������
	Frame(std::wstring);
	Frame(std::wstring, int, int);

	virtual void run();
	
	ToolBar* tbar = nullptr; //���� �ʱ�ȭ
	HINSTANCE hInst_;
	HWND hwnd_;
	//HDC hdc_;
};