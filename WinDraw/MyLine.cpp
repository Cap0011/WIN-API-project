#include "MyLine.h"
MyLine::MyLine(HDC hdc, int l, int t, int r, int b)
	:MyShape(hdc, l, t, r, b)
{

}
void MyLine::repaint() {
	SelectObject(hdc_, myPen);
	SelectObject(hdc_, myBrush);
	//선분 그려주기
	int l = 0;
	int t = 0;
	if (myGroup) {
		Group* temp = myGroup;
		l += temp->getl();
		t += temp->gett();
		while (temp->getGroup()) {
			temp = temp->getGroup();
			l += temp->getl();
			t += temp->gett();
		}
		::MoveToEx(hdc_, left_ +l, top_ + t, NULL);
		::LineTo(hdc_, right_ + l, bottom_ + t);
	}
	else {
		::MoveToEx(hdc_, left_, top_, NULL);
		::LineTo(hdc_, right_, bottom_);
	}
}