#include "TextButton.h"
TextButton::TextButton(HDC hdc, int l, int t, int r, int b, std::string title) 
	:TButton(hdc, l, t, r, b, title)
{
	size = 100;
}