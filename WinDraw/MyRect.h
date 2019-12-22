#pragma once
#include "MyShape.h"
#include "Group.h"
class MyRect :
	public MyShape
{
public:
	MyRect(HDC hdc, int l, int t, int r, int b);
	virtual void repaint();
};

