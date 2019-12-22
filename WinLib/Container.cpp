#include "Container.h"
#include "CheckBox.h"
#include "TextButton.h"
#include "ToolBar.h"
#include "Layout.h"
#include "TextLabel.h"
Container::Container() {
	//EMPTY.
}
Container::Container(HDC hdc, int l, int t, int r, int b, std::string title) 
	:Window(hdc,l,t,r,b,title)
{
	//EMPTY.
}
void Container::Add(Window* c) {
	mylist.push_back(c);
	c->setParent(this);
}
void Container::addLabel(TextLabel* t) {
	Add(t);
	t->setcode(button_num);
	button_num++;
}
bool Container::processMessage(MyEvent m) {
	for(auto win:mylist){
		if(win->processMessage(m)){
			return true;
		}
	}
}
void Container::repaint() {
	for (auto win : mylist) {
		win->repaint();
	}
}
void Container::addlayout(Layout* l) {
	layout_= l;
}
list<Window*> Container::getList() {
	return mylist;
}