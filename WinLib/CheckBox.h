#pragma once
#include "TButton.h"
class CheckBox :
	public TButton
{
public:
	CheckBox(HDC hdc, int l, int t, int r, int b, std::string title);
	virtual bool isChecked(); //üũ ���¸� �˾ƺ��� �޼ҵ�
	virtual void repaint();
};