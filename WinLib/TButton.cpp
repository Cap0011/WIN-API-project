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
	//�ش� ��ư�� �׸���.
	::Rectangle(hdc_, left_, top_, right_, bottom_);
	//�ؽ�Ʈ�� �׸���.
	::TextOutA(hdc_, left_ + 3, top_ + 3, title_.c_str(), strlen(title_.c_str()));
}
bool TButton::belongs(int x, int y) {
	//��ǥ�� ���� �ȿ� ���� ������ return true
	if (x > left_ && x < right_ && y>top_ && y < bottom_) {
		return true;
	}
	else {
		return false;
	}
}
bool TButton::isChecked() {
	//üũ �� ���¸� return true
	return true;
}
void TButton::change() {
	if (!isChecked()) {
		//�������� ���� ���¸� ���� ���·� �ٲ��ֱ�
		check_ = true;
	}
	else {
		//������ ���¸� �������� ���� ���·� �ٲ��ֱ�
		check_ = false;
	}
}
bool TButton::processMessage(MyEvent e) {
	//���콺 ����� ���� �׸� �׸���
	return false;
}