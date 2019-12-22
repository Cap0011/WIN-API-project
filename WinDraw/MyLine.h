#pragma once
#include "MyShape.h"
#include "Group.h"
class MyLine :
	public MyShape
{
public:
	MyLine(HDC hdc, int l, int t, int r, int b);
	virtual void repaint();
	
};

