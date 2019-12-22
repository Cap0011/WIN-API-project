#pragma once
#include <windows.h>
class Group;
class MyShape
{
public:
	MyShape(HDC hdc,int l, int t, int r, int b);
	virtual void repaint() = 0;
	bool belongsF(int, int);//�� ��ǥ�� ���� �ȿ� ���ϴ��� �˷��ִ� �Լ�
	virtual void moveF(int, int);//������ ��ǥ�� �ٲ��ִ� �Լ�
	bool belongsG(int, int, int, int); //������ �� ��ǥ �ȿ� ���ϴ��� �˷��ִ� �Լ�
	virtual void Add(MyShape*);
	virtual void change_min();
	//�� ��ǥ ������
	int getl();
	int gett();
	int getr();
	int getb();
	//��ǥ mutator
	void setl(int);
	void sett(int);
	void setr(int);
	void setb(int);
	//���� �׷� ������ ���� �Լ�
	void setGroup(Group*);
	Group* getGroup();
	virtual void reposition();
	//HPEN 2��
	HPEN myPen;
	//HBRUSH 2��, ��ư���� ���콺�� �ö��� �� ���°�+���� �׸� �� ���� ��
	HBRUSH myBrush;
	HDC hdc_;
protected:
	int left_, top_, right_, bottom_; //��ǥ��
	Group* myGroup=nullptr; //���Ե� �׷� ������
	

};