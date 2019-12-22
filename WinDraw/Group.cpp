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
	//�׷� ���� �׷��ֱ�
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
	//�Ҽ� ���� �׷��ֱ�
	list<MyShape*>::iterator i;
	for (i = m_list->begin(); i != m_list->end(); i++) {
		(*i)->repaint();
	}
}
void Group::moveF(int movex, int movey) {
	//�׷� ��ǥ ����
	MyShape::moveF(movex, movey);
}
void Group::change_min() {
	//l,t,r,b�� �ּڰ����� ����
	int l, t, r, b;
	//����Ʈ�� �� ó�������� ����
	l = (*m_list->begin())->getl();
	t = (*m_list->begin())->gett();
	r = (*m_list->begin())->getr();
	b = (*m_list->begin())->getb();
	list<MyShape*>::iterator i;
	for (i = m_list->begin(); i != m_list->end(); i++) {
		if ((*i)->getl() < l) {
			//���� l���� ������ ����
			l = (*i)->getl();
		}
		if ((*i)->gett() < t) {
			//���� t���� ������ ����
			t = (*i)->gett();
		}
		if ((*i)->getr() > r) {
			//���� r���� ũ�� ����
			r = (*i)->getr();
		}
		if ((*i)->getb() > b) {
			//���� b���� ũ�� ����
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