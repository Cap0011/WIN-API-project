#pragma once
#include "frame.h"
class Layout
{
public:
	Layout(Frame*);
	virtual void doLayout(int,int);//�������ִ� �Լ�

	int width;//�ʺ�
	int height;//����
	int tempw=0;//�����ϱ� ���� �ӽ� ����
	int temph=50;//�����ϱ� ���� �ӽ� ����
	Frame* myFrame;//�Ҽ� ������
};