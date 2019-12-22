#pragma once
#include "Layout.h"
class Gridlayout :
	public Layout
{
public:
	Gridlayout(Frame*,int row);//열 개수 지정
	void doLayout(int, int);

	int size_num;
	int row_;//열 수
};

