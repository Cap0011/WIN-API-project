#pragma once
#include "Layout.h"
class Gridlayout :
	public Layout
{
public:
	Gridlayout(Frame*,int row);//�� ���� ����
	void doLayout(int, int);

	int size_num;
	int row_;//�� ��
};

