#include "MenuBar.h"
Menu* MenuBar::Belongs(int x, int y){
	for (auto win : mylist) {
		if (win->belongs(x, y)) {
			return (Menu*)win;
		}
	}
	return nullptr;
}