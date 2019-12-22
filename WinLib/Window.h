#pragma once
#include "MyEvent.h"
#include <string>
class Container;
class Window
{
public:
	//생성자
	Window();
	Window(HDC hdc, int l, int t, int r, int b, std::string title);
	virtual bool belongs(int, int);
	virtual void repaint();
	virtual bool processMessage(MyEvent m);
	//Window* find();
	//각 좌표 접근자
	int getl();
	int gett();
	int getr();
	int getb();
	//좌표 mutator
	void setl(int);
	void sett(int);
	void setr(int);
	void setb(int);
	void setcode(int); //고유번호 부여 함수
	int getcode();//접근자
	int getsize();
	void setParent(Container* c);
	void setHover();//hover
	void killHover();//hover
//protected:
	int left_, top_, right_, bottom_; //좌표들
	int width_ = 1000; 
	int height_ = 800;
	int size;
	HDC hdc_;
	Container* parent_;
	std::string title_; //이름
	int code;//고유번호
	bool IsHover = false;//hovering?
	//HPEN 2개
	HPEN myPen=CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hover_p= CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
	//HBRUSH 2개, 버튼위로 마우스가 올라갔을 때 쓰는것+평상시 그릴 때 쓰는 것
	HBRUSH myBrush= CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hover_b= CreateSolidBrush(RGB(100,100,100));
};