#pragma once
#include "Container.h"
class ToolBar :public Container
{
public:
	//������
	ToolBar();
	bool isToolBarEvent(MyEvent e); //���� �̺�Ʈ���� �˾Ƴ��� �Լ�
	bool processMessage(MyEvent e);//�޼��� ó�� �Լ�
	Window* find(int, int); //��� ��ư�� ���ϴ��� �˾Ƴ��� �Լ�

	TButton* pressed = nullptr;  // �޴� ��ư�� ������ ���� ����
};