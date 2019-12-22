#pragma once
#include "MyShape.h"
#include "Group.h"
class MyCircle :
	public MyShape
{
public:
	MyCircle(HDC hdc, int l, int t, int r, int b);
	virtual void repaint();

};

