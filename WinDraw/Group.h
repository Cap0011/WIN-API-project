#pragma once
#include "MyShape.h"
#include <iostream>
#include <list>
using namespace std;
class Group :
	public MyShape
{
public:
	Group(HDC hdc, int l, int t, int r, int b);
	virtual void Add(MyShape*); //도형 추가 함수
	virtual void moveF(int, int); //도형 옮기는 함수(위치 수정)
	virtual void repaint(); //그리기
	virtual void change_min(); //위치값 갱신 함수
	virtual void reposition(); //소속 도형을 상대 위치로 바꿔주는 함수
	
private:
	list<MyShape*>* m_list; //도형 리스트
};