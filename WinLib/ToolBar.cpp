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
	//좌표가 포함된 버튼 반환
	for (auto win:mylist) {
		if (win->belongs(x, y))
			return win;
	}
	//해당 사항 없으면 nullptr 반환
	return nullptr;
}
bool ToolBar::isToolBarEvent(MyEvent e) {
	//툴바 이벤트면 true 반환
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
