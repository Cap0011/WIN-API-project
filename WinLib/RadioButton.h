#pragma once
#include "TButton.h"
class RadioButton :
	public TButton
{
public:
	//������
	RadioButton(HDC hdc, int l, int t, int r, int b, std::string title);
};

