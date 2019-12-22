#include "ToolBar.h"
#include "CheckBox.h"
#include "TextButton.h"

ToolBar::ToolBar() {
	left_ = 0;
	top_ = 0;
	right_ = 0;
	bottom_ = 100;
}

Window* ToolBar::find(int x, int y) {
	//��ǥ�� ���Ե� ��ư ��ȯ
	for (auto win:mylist) {
		if (win->belongs(x, y))
			return win;
	}
	//�ش� ���� ������ nullptr ��ȯ
	return nullptr;
}
bool ToolBar::isToolBarEvent(MyEvent e) {
	//���� �̺�Ʈ�� true ��ȯ
	if (e.isMouseEvent() && find(e.x_, e.y_))
		return true;
	return false;
}
bool ToolBar::processMessage(MyEvent e) {
	if (e.isMouseEvent()) {
		Window* b = find(e.x_, e.y_);
		if (b) {
			b->processMessage(e);
			return true;
		}
		return false;
	}
	return true;
}
