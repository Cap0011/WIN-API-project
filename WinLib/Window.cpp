#include "Window.h"
Window::Window() {
	//EMPTY.
	//�����ڿ��� �� �귯�� create
	//hover-> �׵θ� ���ϰ� ������ ȸ��
}
Window::Window(HDC hdc, int l, int t, int r, int b, std::string title) 
	:hdc_(hdc), left_(l), top_(t), right_(r), bottom_(b), title_(title)
{
	//EMPTY.
}
bool Window::belongs(int x, int y) {
	//��ǥ�� ���� �ȿ� ���� ������ return true
	if (x > left_ && x < right_ && y>top_ && y < bottom_) {
		return true;
	}
	else {
		return false;
	}
}
int Window::getl() {
	return left_;
}
int Window::gett() {
	return top_;
}
int Window::getr() {
	return right_;
}
int Window::getb() {
	return bottom_;
}
void Window::setl(int n) {
	left_ = n;
}
void Window::sett(int n) {
	top_ = n;
}
void Window::setr(int n) {
	right_ = n;
}
void Window::setb(int n) {
	bottom_ = n;
}
void Window::repaint() {
	//EMPTY
}
bool Window::processMessage(MyEvent m) {
	//EMPTY.
	return false;
}
void Window::setParent(Container* c) {
	parent_ = c;
}
void Window::setcode(int n) {
	code = n;
}
int Window::getcode() {
	return code;
}
int Window::getsize() {
	return size;
}
void Window::setHover() {
	IsHover = true;
}
void Window::killHover() {
	IsHover = false;
}