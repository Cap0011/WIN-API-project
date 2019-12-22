#include "Group.h"
#include "MyRect.h"
Group::Group(HDC hdc, int l, int t, int r, int b)
	:MyShape(hdc,l,t,r,b)
{
	m_list = new list<MyShape*>;
	myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	myBrush = CreateSolidBrush(RGB(255, 255, 255));
}
void Group::Add(MyShape* s) {
	m_list->push_back(s);
	s->setGroup(this);
}
void Group::repaint() {
	SelectObject(hdc_, myPen);
	SelectObject(hdc_, myBrush);
	int l = 0;
	int t = 0;
	//그룹 범위 그려주기
	if (myGroup) {
		Group* temp = myGroup;
		l += temp->getl();
		t += temp->gett();
		while (temp->getGroup()) {
			temp = temp->getGroup();
			l += temp->getl();
			t += temp->gett();
		}
		::Rectangle(hdc_, left_ + l, top_ + t, right_ + l, bottom_ + t);
	}
	else {
		::Rectangle(hdc_, left_, top_, right_, bottom_);
	}
	//소속 도형 그려주기
	list<MyShape*>::iterator i;
	for (i = m_list->begin(); i != m_list->end(); i++) {
		(*i)->repaint();
	}
}
void Group::moveF(int movex, int movey) {
	//그룹 좌표 변경
	MyShape::moveF(movex, movey);
}
void Group::change_min() {
	//l,t,r,b를 최솟값으로 갱신
	int l, t, r, b;
	//리스트의 맨 처음값으로 지정
	l = (*m_list->begin())->getl();
	t = (*m_list->begin())->gett();
	r = (*m_list->begin())->getr();
	b = (*m_list->begin())->getb();
	list<MyShape*>::iterator i;
	for (i = m_list->begin(); i != m_list->end(); i++) {
		if ((*i)->getl() < l) {
			//기존 l보다 작으면 갱신
			l = (*i)->getl();
		}
		if ((*i)->gett() < t) {
			//기존 t보다 작으면 갱신
			t = (*i)->gett();
		}
		if ((*i)->getr() > r) {
			//기존 r보다 크면 갱신
			r = (*i)->getr();
		}
		if ((*i)->getb() > b) {
			//기존 b보다 크면 갱신
			b = (*i)->getb();
		}
	}
	left_ = l;
	top_ = t;
	right_ = r;
	bottom_ = b;
	reposition();
}
void Group::reposition() {
	list<MyShape*>::iterator i;
	for (i = m_list->begin(); i != m_list->end(); i++) {
		(*i)->setl((*i)->getl() - left_);
		(*i)->setr((*i)->getr() - left_);
		(*i)->sett((*i)->gett() - top_);
		(*i)->setb((*i)->getb() - top_);
	}
}