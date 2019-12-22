using namespace std;
#include "MyCircle.h"
MyCircle::MyCircle(HDC hdc, int l, int t, int r, int b) 
	:MyShape(hdc, l, t, r, b)
{

}

void MyCircle::repaint() {
	SelectObject(hdc_, myPen);
	SelectObject(hdc_, myBrush);
	//타원 그려주기
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
		::Ellipse(hdc_, left_ + l, top_ + t, right_ + l, bottom_ + t);
	}
	else{
		::Ellipse(hdc_, left_, top_, right_, bottom_);
	}
}