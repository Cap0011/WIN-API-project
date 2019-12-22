#include "CheckBox.h"
CheckBox::CheckBox(HDC hdc, int l, int t, int r, int b, std::string title) 
	:TButton(hdc,l,t,r,b,title)
{
	//EMPTY.
}
bool CheckBox::isChecked() {
	//check가 true면 return true
	if (check_) {
		return true;
	}
	else {
		return false;
	}
	//check_=!check_;
}
void CheckBox::repaint() {
	SelectObject(hdc_, myPen);
	//버튼 그려주기
	if (!check_) {
		//체크되지 않았을 때는 사각형 그리기
		::Rectangle(hdc_, left_, top_, right_, bottom_);
		::TextOutA(hdc_, left_ + 30, top_, title_.c_str(), strlen(title_.c_str()));
	}
	else {
		//체크되었을 때는 원 그리기
		::Ellipse(hdc_, left_, top_, right_, bottom_);
		::TextOutA(hdc_, left_ + 30, top_, title_.c_str(), strlen(title_.c_str()));
	}
}
