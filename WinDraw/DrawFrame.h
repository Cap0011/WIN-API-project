#pragma once
#include <frame.h>
#include "MyEvent.h"
#include "MyShape.h"
#include "Group.h"
#include "Menu.h"
#include "MenuBar.h"
#include "MenuItem.h"
class DrawFrame :
	public Frame
{
public:
	//생성자
	DrawFrame(std::wstring w);
	DrawFrame(std::wstring title, int width, int height);

	virtual void run();
	virtual bool processMessage(MyEvent e);
	virtual void repaint();
	int findButton(int x, int y); //해당 범위 버튼값을 반환하는 함수
	void addToolBar();//툴바 인스턴스 추가 함수
	int IsBelongs(int, int); //좌표가 보유 도형 안에 속하는지 판단하는 함수
	bool checkRange(int, int, int, int);//좌표가 알맞은 범위에 있는지 확인하는 함수
	Window* Find(int x, int y); //해당 버튼 반환
	void reset();// 초기화 하는 함수
	void fileopen(); //불러오는 함수
	void filesave();//저장하는 함수
	//void initialize();
private:
	MyShape* myrect[100]; //도형
	int num_rect = 0; //도형 현재 개수
	int num_temp = 0; //임시
	bool check_shape = false; //범위 안에 도형이 있나 확인하는 변수(그룹)
	//int를 저장할 임시 변수
	int startx, starty; //누른 위치 저장
	int code = -1; //도형 파악 변수
	int prev_button = -1;//버튼 다운에서의 버튼/-1->누른 버튼이 없는 것
	int next_button; //버튼 업에서의 버튼
	int num_move = -1;//움직일 도형의 번호
	TButton* button[100];//버튼 임시 저장
	MenuBar* menuBar;//메뉴바
	Menu* menu[5];//메뉴
	MenuItem* menuitem[100];//메뉴 아이템
	bool IsMenuOn = false;//메뉴 펼쳐진 상태 true
	bool IsSave = false;//저장된 상태면 true
	MyShape* temp[100];//임시 저장
	Menu* pressedMenu=nullptr;
	HPEN red;//
	HPEN green;
	HPEN blue;
	HPEN coral;
	HPEN purple;
	HPEN color;
	HPEN black;
	HBRUSH red_b;
	HBRUSH green_b;
	HBRUSH blue_b;
	HBRUSH color_b;
	HBRUSH coral_b;
	HBRUSH purple_b;
	HBRUSH white;
	Window* now;
};