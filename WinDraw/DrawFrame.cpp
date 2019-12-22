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

//������
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
	//���� �߰�
	addToolBar();
	//�޴��� �Ҵ�
	menuBar = new MenuBar();
	menuBar->addlayout(new Flowlayout(this));
	menuBar->layout_->doLayout(1000,800);
	//��ư
	button[0] = new TextButton(hdc_, 0, 20, 50, 40, "�簢��");
	button[1] = new TextButton(hdc_, 50, 20, 100, 40, "��");
	button[2] = new TextButton(hdc_, 100, 20, 150, 40, "����");
	button[3] = new CheckBox(hdc_, 230, 20, 250, 40, "�������� ������");
	button[4] = new CheckBox(hdc_, 380, 20, 400, 40, "�˻����� ������");
	button[5] = new TextButton(hdc_, 150, 20, 230, 40, "���� ����");
	for (int i = 0; i < 6; i++) {
		tbar->Add(button[i]);
		button[i]->setcode(i);
	}
	//�޴�
	menu[0] = new Menu(hdc_, 0, 0, 50, 20, "����");
	menu[1] = new Menu(hdc_, 50, 0, 100, 20, "����");
	menu[2] = new Menu(hdc_, 100, 0, 150, 20, "����");
	menuBar->Add(menu[0]);
	menuBar->Add(menu[1]);
	menuBar->Add(menu[2]);

	//���� �޴� ������
	menuitem[0] = new MenuItem(hdc_, 25, 20, 75, 40, "����");
	menuitem[1] = new MenuItem(hdc_, 25, 40, 75, 60, "����");
	menuitem[2] = new MenuItem(hdc_, 25, 60, 75, 80, "����");
	menuitem[12]= new MenuItem(hdc_, 25, 80, 75, 100, "�����");
	for (int i = 0; i < 3; i++) {
		menu[0]->Add(menuitem[i]);
	}
	menu[0]->Add(menuitem[12]);
	//���� �޴� ������
	menuitem[3] = new MenuItem(hdc_, 75, 20, 125, 40, "�簢��");
	menuitem[4] = new MenuItem(hdc_, 75, 40, 125, 60, "Ÿ��");
	menuitem[5] = new MenuItem(hdc_, 75, 60, 125, 80, "����");
	for (int i = 3; i < 6; i++) {
		menu[1]->Add(menuitem[i]);
	}
	menuitem[6] = new MenuItem(hdc_, 125, 20, 175, 40, "����");
	menuitem[7] = new MenuItem(hdc_, 125, 40, 175, 60, "�ʷ�");
	menuitem[8] = new MenuItem(hdc_, 125, 60, 175, 80, "�Ķ�");
	menuitem[9] = new MenuItem(hdc_, 125, 80, 175, 100, "�ڶ�");
	menuitem[10] = new MenuItem(hdc_, 125, 100, 175, 120, "������");
	menuitem[11] = new MenuItem(hdc_, 125, 120, 175, 140, "�ʱ�ȭ");
	for (int i = 6; i < 12; i++) {
		menu[2]->Add(menuitem[i]);
	}
	Add(menuBar);
	menuBar->repaint();
	tbar->repaint();
	//frame �Լ� ó��
	Frame::repaint();
	Frame::run();
	
}

int DrawFrame::findButton(int x, int y) {
	//�ش�Ǵ� ��ư �� ��ȯ, ������ -1 ��ȯ
	for (auto win:tbar->mylist) {
		if (win->belongs(x, y)) {
			return win->getcode();
		}
	}
	return -1;
}
Window* DrawFrame::Find(int x, int y) {
	//�ش�Ǵ� ��ư ��ȯ
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
	//���� �޸� �Ҵ�
	tbar = new ToolBar();
}
bool DrawFrame::processMessage(MyEvent e) {

	SelectObject(hdc_, black);
	SelectObject(hdc_, white);
	if (!Container::processMessage(e)) {
		switch (e.message_) {
		case WM_LBUTTONDOWN:
		{
			//if n�� ��ư�̸� ��ư ó�� �� return
			startx = e.x_;
			starty = e.y_;
			prev_button = findButton(startx, starty); //��ư ��ȣ ��ȯ
			num_move = IsBelongs(startx, starty);
		}
		break;
		case WM_LBUTTONUP:
		{
			//���� ���� Ŭ������ ��
			if (num_move != -1) {
				if (!e.IsShiftpressed()) {
					//�ش� ������ ��ǥ �ٲ��ֱ�(e.x_-startx,e.y_-starty)
					myrect[num_move]->moveF(e.x_ - startx, e.y_ - starty);
					//�ٽ� -1�� �ٲ��ֱ�
					num_move = -1;
					//�����
					InvalidateRect(hwnd_, NULL, true);
					//�ٽ� �׸���
					repaint();
				}
				else {
					//�����ϱ�
					if (typeid(*myrect[num_move]) == typeid(MyRect)) {
						//�簢�� ����
						myrect[num_rect] = new MyRect(hdc_, e.x_ - startx+ myrect[num_move]->getl(), e.y_ - starty+ myrect[num_move]->gett(), e.x_ - startx+ myrect[num_move]->getr(), e.y_ - starty+ myrect[num_move]->getb());
					}
					else if (typeid(*myrect[num_move]) == typeid(MyCircle)) {
						//�� ����
						myrect[num_rect] = new MyCircle(hdc_, e.x_ - startx + myrect[num_move]->getl(), e.y_ - starty + myrect[num_move]->gett(), e.x_ - startx + myrect[num_move]->getr(), e.y_ - starty + myrect[num_move]->getb());
					}
					else {
						//���� ����
						myrect[num_rect] = new MyLine(hdc_, e.x_ - startx + myrect[num_move]->getl(), e.y_ - starty + myrect[num_move]->gett(), e.x_ - startx + myrect[num_move]->getr(), e.y_ - starty + myrect[num_move]->getb());
					}
					myrect[num_rect]->myPen = myrect[num_move]->myPen;
					myrect[num_rect]->myBrush = myrect[num_move]->myBrush;
					num_move = -1;
					//�׸� �׷��ֱ�
					myrect[num_rect]->repaint();
					//���� ���� �ϳ� ����
					num_rect++;
				}
			}
			//menu ���� ó��
			else if (menuBar->Belongs(startx,starty)== menuBar->Belongs(e.x_,e.y_)&&menuBar->Belongs(e.x_,e.y_)) {
				//�ش� menuItem ���
				//InvalidateRect(hwnd_, NULL, true);
				pressedMenu = menuBar->Belongs(e.x_, e.y_);
				pressedMenu->repaintAll();
				IsMenuOn = true;
			}
			//menuItem ���� ó��
			else if (IsMenuOn && pressedMenu->BelongI(startx, starty) == pressedMenu->BelongI(e.x_, e.y_)) {
				//action �� â �����ֱ�
				if (pressedMenu->BelongI(startx, starty) == menuitem[3]) {
					//�簢��
					code = 0;
					OutputDebugStringA("�簢��.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[4]) {
					//Ÿ��
					code = 1;
					OutputDebugStringA("Ÿ��.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[5]) {
					//����
					code = 2;
					OutputDebugStringA("����.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[0]) {
					OutputDebugStringA("����.\n");
					if (!IsSave) {
						if (MessageBox(hwnd_, L"����� ������ �����ϴ�.", L"WARNING", MB_OK | MB_ICONSTOP) == IDNO) {
							return 0;
						}
						else {
							break;
						}
					}
					else {
						if (MessageBox(hwnd_, L"���� ������ �������ϴ�!", L"WARNING", MB_OK | MB_ICONEXCLAMATION) == IDNO) {
							return 0;
						}
						if (MessageBox(hwnd_, L"���� �ֱٿ� ����� ������ ���ϴ�.", L"FILE", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						//����
						//reset();
						//���� ����
						fileopen();
						repaint();
					}
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[1]) {
					OutputDebugStringA("����.\n");
					filesave();
					reset();
					IsSave = true;
					if (MessageBox(hwnd_, L"����Ǿ����ϴ�", L"SAVE", MB_OK | MB_ICONINFORMATION) == IDNO) {
						return 0;
					}
					else {
						break;
					}
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[2]) {
					OutputDebugStringA("����.\n");
					if (MessageBox(hwnd_, L"���� �����Ͻðڽ��ϱ�?", L"EXIT", MB_YESNO | MB_ICONQUESTION) == IDNO) {
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
					OutputDebugStringA("�ʱ�ȭ.\n");
				}
				else if (pressedMenu->BelongI(startx, starty) == menuitem[12]) {
					reset();
					OutputDebugStringA("�����.\n");
				}
				InvalidateRect(hwnd_, NULL, true);
				IsMenuOn = false;
				pressedMenu = nullptr;
			}
			//���� ���� Ŭ������ ��
			else {
				next_button = findButton(e.x_, e.y_);

				if (next_button == prev_button && next_button >= 0) {
					//�ڵ常 �ٲ��ֱ�
					code = next_button;
				}
				else if (code < 3 && checkRange(startx, starty, e.x_, e.y_)) {
					//�Ҵ� �� �׸� �׸���
					if (code == 1) {
						//1->Ÿ��
						myrect[num_rect] = new MyCircle(hdc_, startx, starty, e.x_, e.y_);
						
					}
					else if (code == 2) {
						//2->����
						myrect[num_rect] = new MyLine(hdc_, startx, starty, e.x_, e.y_);
					}
					else {
						//0 �Ǵ� ������->�簢��
						myrect[num_rect] = new MyRect(hdc_, startx, starty, e.x_, e.y_);
					}
					myrect[num_rect]->myPen = color;
					myrect[num_rect]->myBrush = color_b;

					InvalidateRect(hwnd_, NULL, true);
					//�׸� �׷��ֱ�
					myrect[num_rect]->repaint();
					//���� ���� �ϳ� ����
					num_rect++;
				}
				if (code == 3 || code == 4) {
					//���� ���� ����||�˻� ���� ����
					//���� ���� �ٲ��ֱ�
					button[code]->change();
					//�׷��ְ�
					button[code]->repaint();
					//�׸����� ���� �ڵ� -1�� �ٽ� �ٲ��ֱ�
					code = -1;
				}
				else if (code == 5) {
					//���� ���� ����� �޽��� ����
					if (button[3]->isChecked()) {
						if (MessageBox(hwnd_, L"���� ���� ���ǿ� üũ�Ͽ����ϴ�.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("���� ���� ���ǿ� üũ�Ͽ����ϴ�.\n");
					}
					else {
						if (MessageBox(hwnd_, L"���� ���� ���ǿ� üũ���� �ʾҽ��ϴ�.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("���� ���� ���ǿ� üũ���� �ʾҽ��ϴ�.\n");
					}
					if (button[4]->isChecked()) {
						if (MessageBox(hwnd_, L"�˻� ���� ���ǿ� üũ�Ͽ����ϴ�.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("�˻� ���� ���ǿ� üũ�Ͽ����ϴ�.\n");
					}
					else {
						if (MessageBox(hwnd_, L"�˻� ���� ���ǿ� üũ���� �ʾҽ��ϴ�.", L"CHECK", MB_OK | MB_ICONINFORMATION) == IDNO) {
							return 0;
						}
						OutputDebugStringA("�˻� ���� ���ǿ� üũ���� �ʾҽ��ϴ�.\n");
					}
					//�׸����� ���� �ڵ� -1�� �ٽ� �ٲ��ֱ�
					code = -1;
				}
			}
		}

		break;
		case WM_RBUTTONDOWN:
		{
			//���� ��ǥ ����
			startx = e.x_;
			starty = e.y_;
		}
		break;
		case WM_RBUTTONUP:
		{
			//���� �ȿ� ������ ������
			for (int i = 0; i < num_rect; i++) {
				if (myrect[i]->belongsG(startx, starty, e.x_, e.y_)) {
					check_shape = true;
					break;
				}
				check_shape = false;
			}
			if (check_shape) {
				//group���� �ѱ��
				myrect[num_rect] = new Group(hdc_, startx, starty, e.x_, e.y_);
				//�׷쿡 ���� �߰�
				for (int i = 0; i < num_rect; i++) {
					if (myrect[i]->belongsG(startx, starty, e.x_, e.y_)) {
						myrect[num_rect]->Add(myrect[i]);
					}
				}
				//��ǥ �ٽ� ����
				myrect[num_rect]->change_min();
				//�׷��ֱ�
				InvalidateRect(hwnd_, NULL, true);
				myrect[num_rect]->repaint();
				//���� ���� ����
				num_rect++;
			}
		}
		break;
		case WM_PAINT:
		{
			//���� �׷��ֱ�
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
	//��ư, ���� ��� ���
	Container::repaint();
	tbar->repaint();
	for (int i = 0; i < num_rect; i++) {
		myrect[i]->repaint();
	}
}
int DrawFrame::IsBelongs(int x, int y) {
	//��ǥ�� ���� ���� �ȿ� ���ϴ��� �Ǵ�
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
	//�ʱ�ȭ
	for (int i = 0; i < num_rect; i++) {
		myrect[i] = nullptr;
	}
	num_rect = 0;
	InvalidateRect(hwnd_, NULL, true);
}
void DrawFrame::fileopen(){
	//����
	for (int i = 0; i < num_temp; i++) {
		myrect[i] = temp[i];
	}
	num_rect = num_temp;
}
void DrawFrame::filesave() {
	//����
	for (int i = 0; i < num_rect; i++) {
		temp[i]=myrect[i];
	}
	num_temp = num_rect;
}