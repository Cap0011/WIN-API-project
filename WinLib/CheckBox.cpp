#include "CheckBox.h"
CheckBox::CheckBox(HDC hdc, int l, int t, int r, int b, std::string title) 
	:TButton(hdc,l,t,r,b,title)
{
	//EMPTY.
}
bool CheckBox::isChecked() {
	//check�� true�� return true
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
	//��ư �׷��ֱ�
	if (!check_) {
		//üũ���� �ʾ��� ���� �簢�� �׸���
		::Rectangle(hdc_, left_, top_, right_, bottom_);
		::TextOutA(hdc_, left_ + 30, top_, title_.c_str(), strlen(title_.c_str()));
	}
	else {
		//üũ�Ǿ��� ���� �� �׸���
		::Ellipse(hdc_, left_, top_, right_, bottom_);
		::TextOutA(hdc_, left_ + 30, top_, title_.c_str(), strlen(title_.c_str()));
	}
}
