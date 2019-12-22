#pragma once
#include "MyEvent.h"
#include "Window.h"
#include <string>
class ToolBar;
class TButton:public Window
{
public:
	//������
	TButton(HDC hdc, int l, int t, int r, int b,std::string title);
	virtual void repaint();
	virtual bool isChecked(); //���� �Լ�, üũ�ƴ��� �˷��ִ� �Լ�
	virtual bool belongs(int x, int y);
	bool processMessage(MyEvent e);
	void change();//üũ���� �ٲ��ִ� �Լ�
protected:
	bool check_ = false; //üũ���� ����(������ true)
};