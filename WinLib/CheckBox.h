#pragma once
#include "TButton.h"
class CheckBox :
	public TButton
{
public:
	CheckBox(HDC hdc, int l, int t, int r, int b, std::string title);
	virtual bool isChecked(); //체크 상태를 알아보는 메소드
	virtual void repaint();
};