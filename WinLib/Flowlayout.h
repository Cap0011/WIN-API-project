#pragma once
#include "Layout.h"

class Flowlayout:public Layout
{
public:
	Flowlayout(Frame*);
	void doLayout(int,int);
};

