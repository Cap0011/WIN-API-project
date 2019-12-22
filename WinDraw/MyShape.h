#pragma once
#include <windows.h>
class Group;
class MyShape
{
public:
	MyShape(HDC hdc,int l, int t, int r, int b);
	virtual void repaint() = 0;
	bool belongsF(int, int);//이 좌표가 도형 안에 속하는지 알려주는 함수
	virtual void moveF(int, int);//도형의 좌표를 바꿔주는 함수
	bool belongsG(int, int, int, int); //도형이 이 좌표 안에 속하는지 알려주는 함수
	virtual void Add(MyShape*);
	virtual void change_min();
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
	//포함 그룹 포인터 설정 함수
	void setGroup(Group*);
	Group* getGroup();
	virtual void reposition();
	//HPEN 2개
	HPEN myPen;
	//HBRUSH 2개, 버튼위로 마우스가 올라갔을 때 쓰는것+평상시 그릴 때 쓰는 것
	HBRUSH myBrush;
	HDC hdc_;
protected:
	int left_, top_, right_, bottom_; //좌표들
	Group* myGroup=nullptr; //포함된 그룹 포인터
	

};