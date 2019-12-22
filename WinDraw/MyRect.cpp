#include "MyRect.h"
MyRect::MyRect(HDC hdc, int l, int t, int r, int b)
	:MyShape(hdc, l, t, r, b)
{

}
void MyRect::repaint() {
	//사각형 그려주기
	SelectObject(hdc_, myPen);
	SelectObject(hdc_, myBrush);
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
		::Rectangle(hdc_, left_+ l, top_+ t, right_+ l, bottom_ + t);
	}
	else {
		::Rectangle(hdc_, left_, top_, right_, bottom_);
	}
}
