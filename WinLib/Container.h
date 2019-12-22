#pragma once
#include <list>
#include <iostream>
#include "TButton.h"
#include "Window.h"
#include "TextLabel.h"
class Layout;
class ToolBar;
using namespace std;
class Container :public Window
{
public:
	Container();//생성자
	Container(HDC hdc, int l, int t, int r, int b, std::string title);
	void Add(Window*); //Window 추가 함수
	//텍스트 라벨 추가 함수
	void addLabel(TextLabel*);
	virtual void repaint();
	virtual bool processMessage(MyEvent m); //메시지 처리 함수
	void addlayout(Layout*); //layout 단순 설정
	list<Window*> getList();
	//addwin,resize에서 layout 호출, layout 생성자만 존재(추상 클래스)
	list<Window*> mylist; //Window 리스트
	//현재 버튼 수
	int button_num = 0;
	
	Layout* layout_=nullptr; 
};