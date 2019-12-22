#pragma once
#include <iostream>
#include <list>
using namespace std;
class RadioButton;
class RadioGroup 
{
public:
	RadioGroup();
	virtual void Add(RadioButton*); //버튼 추가 함수
	virtual void repaint(); //그리기

private:
	list<RadioButton*> b_list; //r_button 리스트
	int num_rb=0;//r_button 개수
};