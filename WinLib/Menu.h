#pragma once
#include "Container.h"
class MenuItem;
class Menu :
	public Container
{
public:
	//������
	Menu(HDC hdc, int l, int t, int r, int b, std::string title);
	virtual void repaint();
	void repaintAll();
	MenuItem* BelongI(int,int);
protected:
};