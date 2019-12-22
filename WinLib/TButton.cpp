#include "TButton.h"
TButton::TButton(HDC hdc, int l, int t, int r, int b,std::string title) 
	:Window(hdc,l,t,r,b,title)
{
	//EMPTY.
}
	
void TButton::repaint() {
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
bool TButton::belongs(int x, int y) {
	//좌표가 범위 안에 속해 있으면 return true
	if (x > left_ && x < right_ && y>top_ && y < bottom_) {
		return true;
	}
	else {
		return false;
	}
}
bool TButton::isChecked() {
	//체크 된 상태면 return true
	return true;
}
void TButton::change() {
	if (!isChecked()) {
		//동의하지 않은 상태면 동의 상태로 바꿔주기
		check_ = true;
	}
	else {
		//동의한 상태면 동의하지 않은 상태로 바꿔주기
		check_ = false;
	}
}
bool TButton::processMessage(MyEvent e) {
	//마우스 무브면 새로 그림 그리기
	return false;
}