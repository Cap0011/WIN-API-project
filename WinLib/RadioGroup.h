#pragma once
#include <iostream>
#include <list>
using namespace std;
class RadioButton;
class RadioGroup 
{
public:
	RadioGroup();
	virtual void Add(RadioButton*); //��ư �߰� �Լ�
	virtual void repaint(); //�׸���

private:
	list<RadioButton*> b_list; //r_button ����Ʈ
	int num_rb=0;//r_button ����
};