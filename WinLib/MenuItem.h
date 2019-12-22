#pragma once
#include "TButton.h"
class MenuItem :
	public TButton
{
public:
	//»ý¼ºÀÚ
	MenuItem(HDC hdc, int l, int t, int r, int b, std::string title);
};