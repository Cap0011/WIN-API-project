#include "Layout.h"
Layout::Layout(Frame* f) {
	myFrame = f;
}
void Layout::doLayout(int w, int h) {
	width = w;
	height = h;
}