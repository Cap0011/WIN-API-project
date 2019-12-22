#pragma once
#include "frame.h"
#include "TextLabel.h"
#include "Window.h"
class CalculateFrame:public Frame
{
public:
	//생성자
	CalculateFrame(std::wstring w);
	CalculateFrame(std::wstring title, int width, int height);

	virtual void run();
	Window* findButton(int, int);//해당 버튼을 찾는 함수
	virtual bool processMessage(MyEvent e);//메세지 처리 함수
	void initialize();//초기화 함수
	//virtual void buttonCallback(TButton*);

protected:
	Window* prev_=nullptr;//버튼 다운 때 눌린 버튼
	Window* next_=nullptr;//버튼 업 때 눌린 버튼
	TButton* but[100];
	int row_ = 3;
	TextLabel* display=nullptr;
};

