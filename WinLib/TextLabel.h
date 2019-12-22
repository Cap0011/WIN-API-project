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
	void remove();//창 지워주기
	void save();//realvalue에 저장
	void calculate();//최종 계산
	void dot();//소수점 처리
	//processmessage 막아주기
	int mode = 0;//0은 정수 1은 실수
	//정수
	long long int value_ = 0; //화면에 보이는 값
	long long int real_value_ = 0; //실제 값
	//실수
	double fvalue_ = 0; 
	double freal_value_ = 0;
	double dividen = 0.1;//자릿수 저장
	bool isDot=false;//소숫점 뒷자리면 true
};