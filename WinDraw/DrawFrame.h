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
	//������
	DrawFrame(std::wstring w);
	DrawFrame(std::wstring title, int width, int height);

	virtual void run();
	virtual bool processMessage(MyEvent e);
	virtual void repaint();
	int findButton(int x, int y); //�ش� ���� ��ư���� ��ȯ�ϴ� �Լ�
	void addToolBar();//���� �ν��Ͻ� �߰� �Լ�
	int IsBelongs(int, int); //��ǥ�� ���� ���� �ȿ� ���ϴ��� �Ǵ��ϴ� �Լ�
	bool checkRange(int, int, int, int);//��ǥ�� �˸��� ������ �ִ��� Ȯ���ϴ� �Լ�
	Window* Find(int x, int y); //�ش� ��ư ��ȯ
	void reset();// �ʱ�ȭ �ϴ� �Լ�
	void fileopen(); //�ҷ����� �Լ�
	void filesave();//�����ϴ� �Լ�
	//void initialize();
private:
	MyShape* myrect[100]; //����
	int num_rect = 0; //���� ���� ����
	int num_temp = 0; //�ӽ�
	bool check_shape = false; //���� �ȿ� ������ �ֳ� Ȯ���ϴ� ����(�׷�)
	//int�� ������ �ӽ� ����
	int startx, starty; //���� ��ġ ����
	int code = -1; //���� �ľ� ����
	int prev_button = -1;//��ư �ٿ���� ��ư/-1->���� ��ư�� ���� ��
	int next_button; //��ư �������� ��ư
	int num_move = -1;//������ ������ ��ȣ
	TButton* button[100];//��ư �ӽ� ����
	MenuBar* menuBar;//�޴���
	Menu* menu[5];//�޴�
	MenuItem* menuitem[100];//�޴� ������
	bool IsMenuOn = false;//�޴� ������ ���� true
	bool IsSave = false;//����� ���¸� true
	MyShape* temp[100];//�ӽ� ����
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