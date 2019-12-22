#pragma once
#include "MyEvent.h"
#include <string>
class Container;
class Window
{
public:
	//������
	Window();
	Window(HDC hdc, int l, int t, int r, int b, std::string title);
	virtual bool belongs(int, int);
	virtual void repaint();
	virtual bool processMessage(MyEvent m);
	//Window* find();
	//�� ��ǥ ������
	int getl();
	int gett();
	int getr();
	int getb();
	//��ǥ mutator
	void setl(int);
	void sett(int);
	void setr(int);
	void setb(int);
	void setcode(int); //������ȣ �ο� �Լ�
	int getcode();//������
	int getsize();
	void setParent(Container* c);
	void setHover();//hover
	void killHover();//hover
//protected:
	int left_, top_, right_, bottom_; //��ǥ��
	int width_ = 1000; 
	int height_ = 800;
	int size;
	HDC hdc_;
	Container* parent_;
	std::string title_; //�̸�
	int code;//������ȣ
	bool IsHover = false;//hovering?
	//HPEN 2��
	HPEN myPen=CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hover_p= CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
	//HBRUSH 2��, ��ư���� ���콺�� �ö��� �� ���°�+���� �׸� �� ���� ��
	HBRUSH myBrush= CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hover_b= CreateSolidBrush(RGB(100,100,100));
};