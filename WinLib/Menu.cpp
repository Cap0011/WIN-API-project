#include "Menu.h"
Menu::Menu(HDC hdc, int l, int t, int r, int b, std::string title)
	:Container(hdc,l,t,r,b,title)
{
	//EMPTY.
}
void Menu::repaint() {
	if (!IsHover) {
		SelectObject(hdc_, myPen);
		SelectObject(hdc_, myBrush);
	}
	else {
		SelectObject(hdc_, hover_p);
		SelectObject(hdc_, hover_b);
	}
	//해당 버튼을 그린다.
	::Rectangle(hdc_, left_, top_, right_, bottom_);
	//텍스트를 그린다.
	::TextOutA(hdc_, left_ + 3, top_ + 3, title_.c_str(), strlen(title_.c_str()));
}
void Menu::repaintAll() {
	
	Container::repaint();
	Menu::repaint();
	/*if (!IsHover) {
		SelectObject(hdc_, myPen);
		SelectObject(hdc_, myBrush);
	}
	else {
		SelectObject(hdc_, hover_p);
		SelectObject(hdc_, hover_b);
	}
	//해당 버튼을 그린다.
	::Rectangle(hdc_, left_, top_, right_, bottom_);
	//텍스트를 그린다.
	::TextOutA(hdc_, left_ + 3, top_ + 3, title_.c_str(), strlen(title_.c_str()));*/
}
MenuItem* Menu::BelongI(int x, int y) {
	for (auto win : mylist) {
		if (win->belongs(x, y)) {
			return (MenuItem*)win;
		}
	}
	return nullptr;
}