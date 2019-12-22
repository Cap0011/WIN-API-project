#pragma once
#include "Container.h"
class Menu;
class MenuItem;
class MenuBar :
	public Container
{
public:
	Menu* Belongs(int,int);//해당 메뉴 반환
};