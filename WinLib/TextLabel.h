#pragma once
#include "TButton.h"
class TextLabel :
	public TButton
{
public:
	TextLabel(HDC hdc, int l, int t, int r, int b, std::string title);
	void changeMode();
	void setValue(int);
	void repaint();
	void remove();//â �����ֱ�
	void save();//realvalue�� ����
	void calculate();//���� ���
	void dot();//�Ҽ��� ó��
	//processmessage �����ֱ�
	int mode = 0;//0�� ���� 1�� �Ǽ�
	//����
	long long int value_ = 0; //ȭ�鿡 ���̴� ��
	long long int real_value_ = 0; //���� ��
	//�Ǽ�
	double fvalue_ = 0; 
	double freal_value_ = 0;
	double dividen = 0.1;//�ڸ��� ����
	bool isDot=false;//�Ҽ��� ���ڸ��� true
};