#pragma once
#include "TButton.h"
class TextButton :
	public TButton
{
public:
	//������
	TextButton(HDC hdc, int l, int t, int r, int b, std::string title);
};