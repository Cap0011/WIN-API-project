#pragma once
#include "MyEvent.h"
#include "Window.h"
#include <string>
class ToolBar;
class TButton:public Window
{
public:
	//생성자
	TButton(HDC hdc, int l, int t, int r, int b,std::string title);
	virtual void repaint();
	virtual bool isChecked(); //가상 함수, 체크됐는지 알려주는 함수
	virtual bool belongs(int x, int y);
	bool processMessage(MyEvent e);
	void change();//체크상태 바꿔주는 함수
protected:
	bool check_ = false; //체크상태 저장(눌리면 true)
};