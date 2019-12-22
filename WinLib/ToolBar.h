#pragma once
#include "Container.h"
class ToolBar :public Container
{
public:
	//생성자
	ToolBar();
	bool isToolBarEvent(MyEvent e); //툴바 이벤트인지 알아내는 함수
	bool processMessage(MyEvent e);//메세지 처리 함수
	Window* find(int, int); //어느 버튼에 속하는지 알아내는 함수

	TButton* pressed = nullptr;  // 메뉴 버튼의 누르고 뗌을 추적
};