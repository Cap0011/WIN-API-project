#pragma once
#include "MyShape.h"
#include <iostream>
#include <list>
using namespace std;
class Group :
	public MyShape
{
public:
	Group(HDC hdc, int l, int t, int r, int b);
	virtual void Add(MyShape*); //���� �߰� �Լ�
	virtual void moveF(int, int); //���� �ű�� �Լ�(��ġ ����)
	virtual void repaint(); //�׸���
	virtual void change_min(); //��ġ�� ���� �Լ�
	virtual void reposition(); //�Ҽ� ������ ��� ��ġ�� �ٲ��ִ� �Լ�
	
private:
	list<MyShape*>* m_list; //���� ����Ʈ
};