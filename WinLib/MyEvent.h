#pragma once
#include <windows.h>
class MyEvent
{
public:
	MyEvent(UINT message,WPARAM wParam,LPARAM lParam);
	//Ű�� ���ȴ��� Ȯ���ϴ� �Լ�
	bool IsControlpressed();
	bool IsShiftpressed();
	//mouse event���� �˷��ִ� �Լ�
	bool isMouseEvent();

	UINT message_; //�̺�Ʈ Ÿ��
	WPARAM wParam_;
	LPARAM lParam_;
	int x_, y_; //���콺 ��ǥ
};

