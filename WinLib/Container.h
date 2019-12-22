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
	Container();//������
	Container(HDC hdc, int l, int t, int r, int b, std::string title);
	void Add(Window*); //Window �߰� �Լ�
	//�ؽ�Ʈ �� �߰� �Լ�
	void addLabel(TextLabel*);
	virtual void repaint();
	virtual bool processMessage(MyEvent m); //�޽��� ó�� �Լ�
	void addlayout(Layout*); //layout �ܼ� ����
	list<Window*> getList();
	//addwin,resize���� layout ȣ��, layout �����ڸ� ����(�߻� Ŭ����)
	list<Window*> mylist; //Window ����Ʈ
	//���� ��ư ��
	int button_num = 0;
	
	Layout* layout_=nullptr; 
};