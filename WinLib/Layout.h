#pragma once
#include "frame.h"
class Layout
{
public:
	Layout(Frame*);
	virtual void doLayout(int,int);//조정해주는 함수

	int width;//너비
	int height;//높이
	int tempw=0;//조정하기 위한 임시 변수
	int temph=50;//조정하기 위한 임시 변수
	Frame* myFrame;//소속 프레임
};