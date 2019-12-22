#include "DrawFrame.h"
#include "ToolBar.h"
#include "MyRect.h"
#include "MyCircle.h"
#include "MyLine.h"
#include "TextButton.h"
#include "CheckBox.h"
#include "Menu.h"
#include "Flowlayout.h"
#include <typeinfo>

//생성자
DrawFrame::DrawFrame(std::wstring title, int width, int height) : Frame(title, width, height) {
	//EMPTY.
}
DrawFrame::DrawFrame(std::wstring w)
	: Frame(w, 1000, 800)
{
	//EMPTY.
	red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	green = CreatePen(PS_SOLID, 1, RGB(71, 200, 62));
	blue = CreatePen(PS_SOLID, 1, RGB(67, 116, 217));
	coral = CreatePen(PS_SOLID, 1, RGB(255, 111, 97));
	purple = CreatePen(PS_SOLID, 1, RGB(209, 178, 255));
	red_b = CreateSolidBrush(RGB(255, 0, 0));
	green_b = CreateSolidBrush(RGB(71, 200, 62));
	blue_b = CreateSolidBrush(RGB(67, 116, 217));
	coral_b = CreateSolidBrush(RGB(255, 111, 97));
	purple_b = CreateSolidBrush(RGB(209, 178, 255));
	black= CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	white = CreateSolidBrush(RGB(255, 255, 255));
}
void DrawFrame::run() {
	//툴바 추가
	addToolBar();
	//메뉴바 할당
	menuBar = new MenuBar();
	menuBar->addlayout(new Flowlayout(this));
	menuBar->layout_->doLayout(1000,800);
	//버튼
	button[0] = new TextButton(hdc_, 0, 20, 50, 40, "사각형");
	button[1] = new TextButton(hdc_, 50, 20, 100, 40, "원");
	button[2] = new TextButton(hdc_, 100, 20, 150, 40, "선분");
	button[3] = new CheckBox(hdc_, 230, 20, 250, 40, "정보공개 동의함");
	button[4] = new CheckBox(hdc_, 380, 20, 400, 40, "검색노출 동의함");
	button[5] = new TextButton(hdc_, 150, 20, 230, 40, "동의 여부");
	for (int i = 0; i < 6; i++) {
		tbar->Add(button[i]);
		button[i]->setcode(i);
	}
	//메뉴
	menu[0] = new Menu(hdc_, 0, 0, 50, 20, "파일");
	menu[1] = new Menu(hdc_, 50, 0, 100, 20, "도형");
	menu[2] = new Menu(hdc_, 100, 0, 150, 20, "색깔");
	menuBar->Add(menu[0]);
	menuBar->Add(menu[1]);
	menuBar->Add(menu[2]);

	//파일 메뉴 아이템
	menuitem[0] = new MenuItem(hdc_, 25, 20, 75, 40, "열기");
	menuitem[1] = new MenuItem(hdc_, 25, 40, 75, 60, "저장");
	menuitem[2] = new MenuItem(hdc_, 25, 60, 75, 80, "종료");
	menuitem[12]= new MenuItem(hdc_, 25, 80, 75, 100, "지우기");
	for (int i = 0; i < 3; i++) {
		menu[0]->Add(menuitem[i]);
	}
	menu[0]->Add(menuitem[12]);
	//도형 메뉴 아이템
	menuitem[3] = new MenuItem(hdc_, 75, 20, 125, 40, "사각형");
	menuitem[4] = new MenuItem(hdc_, 75, 40, 125, 60, "타원");
	menuitem[5] = new MenuItem(hdc_, 75, 60, 125, 80, "선분");
	for (int i = 3; i < 6; i++) {
		menu[1]->Add(menuitem[i]);
	}
	menuitem[6] = new MenuItem(hdc_, 125, 20, 175, 40, "빨강");
	menuitem[7] = new MenuItem(hdc_, 125, 40, 175, 60, "초록");
	menuitem[8] = new MenuItem(hdc_, 125, 60, 175, 80, "파랑");
	menuitem[9] = new MenuItem(hdc_, 125, 80, 175, 100, "코랄");
	menuitem[10] = new MenuItem(hdc_, 125, 100, 175, 120, "연보라");
	menuitem[11] = new MenuItem(hdc_, 125, 120, 175, 140, "초기화");
	for (int i = 6; i < 12; i++) {
		menu[2]->Add(menuitem[i]);
	}
	Add(menuBar);
	menuBar->repaint();
	tbar->repaint();
	//frame 함수 처리
	Frame::repaint();
	Frame::run();
	
}

int DrawFrame::findButton(int x, int y) {
	//해당되는 버튼 값 반환, 없으면 -1 반환
	for (auto win:tbar->mylist) {
		if (win->belongs(x, y)) {
			return win->getcode();
		}
	}
	return -1;
}
Window* DrawFrame::Find(int x, int y) {
	//해당되는 버튼 반환
	if (menuBar->Belongs(x, y)) {
		return menuBar->Belongs(x, y);
	}
	for (auto win : tbar->mylist) {
		if (win->belongs(x, y)) {
			return win;
		}
	}
	return nullptr;
}
void DrawFrame::addToolBar() {
	//툴바 메모리 할당
	tbar = new ToolBar();
}
bool DrawFrame::processMessage(MyEvent e) {

	SelectObject(hdc_, black);
	SelectObject(hdc_, white);
	if (!Container::processMessage(e)) {
		switch (e.message_) {
		case WM_LBUTTONDOWN:
		{
			//if n이 버튼이면 버튼 처리 후 return
			startx = e.x_;
			starty = e.y_;
			prev_button = findButton(startx, starty); //버튼 번호 반환
			num_move = IsBelongs(startx, starty);
		}
		break;
		case WM_LBUTTONUP:
		{
			//도형 안을 클릭했을 때
			if (num_move != -1) {
				if (!e.IsShiftpressed()) {
					//해당 도형의 좌표 바꿔주기(e.x_-startx,e.y_-starty)
					myrect[num_move]->moveF(e.x_ - startx, e.y_ - starty);
					//다시 -1로 바꿔주기
					num_move = -1;
					//지우고
					InvalidateRect(hwnd_, NULL, true);
					//다시 그리기
					repaint();
				}
				else {
					//복사하기
					if (typeid(*myrect[num_move]) == typeid(MyRect)) {
						//사각형 복사
						myrect[num_rect] = new MyRect(hdc_, e.x_ - startx+ myrect[num_move]->getl(), e.y_ - starty+ myrect[num_move]->gett(), e.x_ - startx+ myrect[num_move]->getr(), e.y_ - starty+ myrect[num_move]->getb());
					}
					else if (typeid(*myrect[num_move]) == typeid(MyCircle)) {
						//원 복사
						myrect[num_rect] = new MyCircle(hdc_, e.x_ - startx + myrect[num_move]->getl(), e.y_ - starty + myrect[num_move]->gett(), e.x_ - startx + myrect[num_move]->getr(), e.y_ - starty + myrect[num_move]->getb());
					}
					else {
						//선분 복사
						myrect[num_rect] = new MyLine(hdc_, e.x_ - startx + myrect[num_move]->getl(), e.y_ - starty + myrect[num_move]->gett(), e.x_ - startx + myrect[num_move]->getr(), e.y_ - starty + myrect[num_move]->getb());
					}
					myrect[num_rect]->myPen = myrect[num_move]->myPen;
					myrect[num_rect]->myBrush = myrect[num_move]->myBrush;
					num_move = -1;
					//그림 그려주기
					myrect[num_rect]->repaint();
					//도형 숫자 하나 증가
					num_rect++;
				}
			}
			//menu 관련 처리
			else if (menuBar->Belongs(startx,starty)== menuBar->Belongs(e.x_,e.y_)&&menuBar->Belongs(e.x_,e.y_)) {
				//해당 menuItem 출력
				//InvalidateRect(hwnd_, NULL, true);
				pressedMenu = menuBar->Belongs(e.x_, e.y_);
				pressedMenu->repaintAll();
				IsMenuOn = true;
			}
			//menuItem 관련 처리
			else if (IsMenuOn && pressedMenu->BelongI(startx, starty) == pressedMenu->BelongI(e.x_, e.y_)) {
				//action 후 창 지워주기
				if (pressedMenu->BelongI(startx, starty) == menuitem[3]) {
					//사각형
					code = 0;
					OutputDebugStringA("사각형.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[4]) {
					//타원
					code = 1;
					OutputDebugStringA("타원.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[5]) {
					//선분
					code = 2;
					OutputDebugStringA("선분.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[0]) {
					OutputDebugStringA("열기.\n");
					if (!IsSave) {
						if (MessageBox(hwnd_, L"저장된 파일이 없습니다.", L"WARNING", MB_OK | MB_ICONSTOP) == IDNO) {
							return 0;
						}
						else {
							break;
						}
					}
					else {
						if (MessageBox(hwnd_, L"현재 파일은 지워집니다!", L"WARNING", MB_OK | MB_ICONEXCLAMATION) == IDNO) {
							return 0;
						}
						if (MessageBox(hwnd_, L"가장 최근에 저장된 파일을 엽니다.", L"FILE", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						//리셋
						//reset();
						//파일 열기
						fileopen();
						repaint();
					}
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[1]) {
					OutputDebugStringA("저장.\n");
					filesave();
					reset();
					IsSave = true;
					if (MessageBox(hwnd_, L"저장되었습니다", L"SAVE", MB_OK | MB_ICONINFORMATION) == IDNO) {
						return 0;
					}
					else {
						break;
					}
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[2]) {
					OutputDebugStringA("종료.\n");
					if (MessageBox(hwnd_, L"정말 종료하시겠습니까?", L"EXIT", MB_YESNO | MB_ICONQUESTION) == IDNO) {
						return 0;
					}
					else {
						SendMessage(hwnd_, WM_DESTROY, 0, 0);
						break;
					}
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[6]) {
					color = red;
					color_b = red_b;
					OutputDebugStringA("red.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[7]) {
					color = green;
					color_b = green_b;
					OutputDebugStringA("green.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[8]) {
					color = blue;
					color_b = blue_b;
					OutputDebugStringA("blue.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[9]) {
					color = coral;
					color_b = coral_b;
					OutputDebugStringA("coral.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[10]) {
					color = purple;
					color_b = purple_b;
					OutputDebugStringA("purple.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[11]) {
					color = myPen;
					color_b = myBrush;
					OutputDebugStringA("초기화.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[12]) {
					reset();
					OutputDebugStringA("지우기.\n");
				}
				InvalidateRect(hwnd_, NULL, true);
				IsMenuOn = false;
				pressedMenu = nullptr;
			}
			//도형 밖을 클릭했을 때
			else {
				next_button = findButton(e.x_, e.y_);

				if (next_button == prev_button && next_button >= 0) {
					//코드만 바꿔주기
					code = next_button;
				}
				else if (code < 3 && checkRange(startx, starty, e.x_, e.y_)) {
					//할당 후 그림 그리기
					if (code == 1) {
						//1->타원
						myrect[num_rect] = new MyCircle(hdc_, startx, starty, e.x_, e.y_);
						
					}
					else if (code == 2) {
						//2->선분
						myrect[num_rect] = new MyLine(hdc_, startx, starty, e.x_, e.y_);
					}
					else {
						//0 또는 나머지->사각형
						myrect[num_rect] = new MyRect(hdc_, startx, starty, e.x_, e.y_);
					}
					myrect[num_rect]->myPen = color;
					myrect[num_rect]->myBrush = color_b;

					InvalidateRect(hwnd_, NULL, true);
					//그림 그려주기
					myrect[num_rect]->repaint();
					//도형 숫자 하나 증가
					num_rect++;
				}
				if (code == 3 || code == 4) {
					//정보 공개 동의||검색 노출 동의
					//동의 상태 바꿔주기
					button[code]->change();
					//그려주고
					button[code]->repaint();
					//그림판을 위해 코드 -1로 다시 바꿔주기
					code = -1;
				}
				else if (code == 5) {
					//동의 여부 디버그 메시지 띄우기
					if (button[3]->isChecked()) {
						if (MessageBox(hwnd_, L"정보 공개 동의에 체크하였습니다.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("정보 공개 동의에 체크하였습니다.\n");
					}
					else {
						if (MessageBox(hwnd_, L"정보 공개 동의에 체크하지 않았습니다.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("정보 공개 동의에 체크하지 않았습니다.\n");
					}
					if (button[4]->isChecked()) {
						if (MessageBox(hwnd_, L"검색 노출 동의에 체크하였습니다.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("검색 노출 동의에 체크하였습니다.\n");
					}
					else {
						if (MessageBox(hwnd_, L"검색 노출 동의에 체크하지 않았습니다.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("검색 노출 동의에 체크하지 않았습니다.\n");
					}
					//그림판을 위해 코드 -1로 다시 바꿔주기
					code = -1;
				}
			}
		}

		break;
		case WM_RBUTTONDOWN:
		{
			//시작 좌표 저장
			startx = e.x_;
			starty = e.y_;
		}
		break;
		case WM_RBUTTONUP:
		{
			//범위 안에 도형이 있으면
			for (int i = 0; i < num_rect; i++) {
				if (myrect[i]->belongsG(startx, starty, e.x_, e.y_)) {
					check_shape = true;
					break;
				}
				check_shape = false;
			}
			if (check_shape) {
				//group으로 넘기기
				myrect[num_rect] = new Group(hdc_, startx, starty, e.x_, e.y_);
				//그룹에 도형 추가
				for (int i = 0; i < num_rect; i++) {
					if (myrect[i]->belongsG(startx, starty, e.x_, e.y_)) {
						myrect[num_rect]->Add(myrect[i]);
					}
				}
				//좌표 다시 갱신
				myrect[num_rect]->change_min();
				//그려주기
				InvalidateRect(hwnd_, NULL, true);
				myrect[num_rect]->repaint();
				//도형 개수 증가
				num_rect++;
			}
		}
		break;
		case WM_PAINT:
		{
			//도형 그려주기
			this->repaint();
			menuBar->repaint();
		}
		break;
		case WM_MOUSEMOVE:
		{
			if (!IsMenuOn) {
				if (now) {
					if (now != Find(e.x_, e.y_)) {
						now->killHover();
						now->repaint();
					}
				}
				now = Find(e.x_, e.y_);
				if (now) {
					//OutputDebugStringA("hover.");
					now->setHover();
					now->repaint();
				}
			}
		}
		break;
		}
	}
	return true;
}
void DrawFrame::repaint() {
	//버튼, 도형 모두 출력
	Container::repaint();
	tbar->repaint();
	for (int i = 0; i < num_rect; i++) {
		myrect[i]->repaint();
	}
}
int DrawFrame::IsBelongs(int x, int y) {
	//좌표가 보유 도형 안에 속하는지 판단
	for (int i = num_rect - 1; i >= 0; i--) {
		if (myrect[i]->belongsF(x, y)) {
			return i;
		}
	}
	return -1;
}
bool DrawFrame::checkRange(int l, int t, int r, int b) {
	if (l < r && t < b) {
		return true;
	}
	return false;
}
void DrawFrame::reset() {
	//초기화
	for (int i = 0; i < num_rect; i++) {
		myrect[i] = nullptr;
	}
	num_rect = 0;
	InvalidateRect(hwnd_, NULL, true);
}
void DrawFrame::fileopen(){
	//저장
	for (int i = 0; i < num_temp; i++) {
		myrect[i] = temp[i];
	}
	num_rect = num_temp;
}
void DrawFrame::filesave() {
	//저장
	for (int i = 0; i < num_rect; i++) {
		temp[i]=myrect[i];
	}
	num_temp = num_rect;
}