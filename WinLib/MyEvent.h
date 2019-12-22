#pragma once
#include <windows.h>
class MyEvent
{
public:
	MyEvent(UINT message,WPARAM wParam,LPARAM lParam);
	//키가 눌렸는지 확인하는 함수
	bool IsControlpressed();
	bool IsShiftpressed();
	//mouse event인지 알려주는 함수
	bool isMouseEvent();

	UINT message_; //이벤트 타입
	WPARAM wParam_;
	LPARAM lParam_;
	int x_, y_; //마우스 좌표
};

