#include "MyShape.h"
MyShape::MyShape(HDC hdc,int l, int t, int r, int b) 
	:left_(l),top_(t),right_(r),bottom_(b),hdc_(hdc)
{
	//EMPTY
}
bool MyShape::belongsF(int x, int y) {
	//좌표가 범위 안에 속해 있으면 return true
	if (myGroup) {
		return false;
	}
	if (x > left_ && x < right_ && y>top_ && y < bottom_) {
		return true;
	}
	return false;
}
void MyShape::moveF(int xmove, int ymove) {
	//x변화량 y변화량만큼 좌표를 변경한다.
	left_ += xmove;
	top_ += ymove;
	right_ += xmove;
	bottom_ += ymove;
}
bool MyShape::belongsG(int x1, int y1, int x2, int y2) {
	//도형이 좌표 안에 속해 있으면 return true
	if (left_ > x1 && left_<x2 && right_>x1 && right_ < x2 && top_>y1 && top_<y2 && bottom_>y1 && bottom_ < y2) {
		return true;
	}
	return false;
}
void MyShape::Add(MyShape*) {

}
void MyShape::change_min() {

}
int MyShape::getl() {
	return left_;
}
int MyShape::gett() {
	return top_;
}
int MyShape::getr() {
	return right_;
}
int MyShape::getb() {
	return bottom_;
}
void MyShape::setl(int n) {
	left_= n;
}
void MyShape::sett(int n) {
	top_= n;
}
void MyShape::setr(int n) {
	right_= n;
}
void MyShape::setb(int n) {
	bottom_= n;
}
void MyShape::setGroup(Group* g) {
	myGroup = g;
}
void MyShape::reposition() {
}
Group* MyShape::getGroup() {
	return myGroup;
}