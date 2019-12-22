#pragma once
#include "frame.h"
#include "TextLabel.h"
#include "Window.h"
class CalculateFrame:public Frame
{
public:
	//������
	CalculateFrame(std::wstring w);
	CalculateFrame(std::wstring title, int width, int height);

	virtual void run();
	Window* findButton(int, int);//�ش� ��ư�� ã�� �Լ�
	virtual bool processMessage(MyEvent e);//�޼��� ó�� �Լ�
	void initialize();//�ʱ�ȭ �Լ�
	//virtual void buttonCallback(TButton*);

protected:
	Window* prev_=nullptr;//��ư �ٿ� �� ���� ��ư
	Window* next_=nullptr;//��ư �� �� ���� ��ư
	TButton* but[100];
	int row_ = 3;
	TextLabel* display=nullptr;
};

