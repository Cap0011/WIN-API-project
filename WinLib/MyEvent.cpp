#include "MyEvent.h"
MyEvent::MyEvent(UINT message, WPARAM wParam, LPARAM lParam)
	:message_(message),wParam_(wParam),lParam_(lParam)
{
	//Empty.
	x_ = LOWORD(lParam); //
	y_ = HIWORD(lParam); //
}
bool MyEvent::IsControlpressed() {
	//��Ʈ�� Ű�� �������� ��ȯ
	return wParam_ & MK_CONTROL;
}
bool MyEvent::IsShiftpressed() {
	//shift Ű�� �������� ��ȯ
	return wParam_ & MK_SHIFT;
}
bool MyEvent::isMouseEvent() {
	return message_ == WM_LBUTTONDOWN
		|| message_ == WM_LBUTTONUP
		|| message_ == WM_LBUTTONDBLCLK
		|| message_ == WM_RBUTTONDOWN
		|| message_ == WM_RBUTTONUP
		|| message_ == WM_LBUTTONDBLCLK;
}