#include "CalculateFrame.h"
#include "Flowlayout.h"
#include "Gridlayout.h"
#include "TextButton.h"
#include "RadioGroup.h"
#include "RadioButton.h"
#include "CheckBox.h"
//생성자
CalculateFrame::CalculateFrame(std::wstring title, int width, int height) : Frame(title, width, height) {
	//EMPTY.
}
CalculateFrame::CalculateFrame(std::wstring w)
	: Frame(w, 1000, 800)
{
	//EMPTY.
}
void CalculateFrame::initialize() {
	//툴바 추가
	tbar = new ToolBar();
	//RadioGroup 추가(툴바에 소속시키기)
	RadioGroup* rgroup = new RadioGroup();
	tbar->Add((Window*)rgroup);
	//디스플레이 추가
	display = new TextLabel(hdc_, 50, 450, 500, 550, "display");

	//숫자 버튼 추가
	but[0] = new TextButton(hdc_, 0, 0, 0, 0, "0");
	but[1] = new TextButton(hdc_, 0, 0, 0, 0, "1");
	but[2] = new TextButton(hdc_, 0, 0, 0, 0, "2");
	but[3] = new TextButton(hdc_, 0, 0, 0, 0, "3");
	but[4] = new TextButton(hdc_, 0, 0, 0, 0, "4");
	but[5] = new TextButton(hdc_, 0, 0, 0, 0, "5");
	but[6] = new TextButton(hdc_, 0, 0, 0, 0, "6");
	but[7] = new TextButton(hdc_, 0, 0, 0, 0, "7");
	but[8] = new TextButton(hdc_, 0, 0, 0, 0, "8");
	but[9] = new TextButton(hdc_, 0, 0, 0, 0, "9");
	but[10] = new TextButton(hdc_, 0, 0, 0, 0, "+");
	but[11] = new TextButton(hdc_, 0, 0, 0, 0, "-");
	but[12] = new TextButton(hdc_, 0, 0, 0, 0, "*");
	but[13] = new TextButton(hdc_, 0, 0, 0, 0, "/");
	but[14] = new TextButton(hdc_, 0, 0, 0, 0, "=");
	but[15] = new TextButton(hdc_, 0, 0, 0, 0, "clear");
	but[16] = new TextButton(hdc_, 0, 0, 0, 0, ".");
	but[17] = new RadioButton(hdc_, 0, 0, 100, 50, "정수");
	but[18] = new RadioButton(hdc_, 100, 0, 200, 50, "실수");
	but[19] = new CheckBox(hdc_, 200, 0, 300, 50, "구색 맞추기용 체크 박스");
	but[17]->setcode(17);
	but[18]->setcode(18);
	but[19]->setcode(19);
	tbar->Add(but[19]);
	//RadioGroup에 버튼 추가
	rgroup->Add((RadioButton*)but[17]);
	rgroup->Add((RadioButton*)but[18]);
	rgroup->repaint();
	//윈도 리스트에 추가해주기
	for (int i = 0; i < 17; i++) {
		Add(but[i]);
		but[i]->setcode(button_num);
		button_num++;
	}
	addLabel(display);

	//addlayout(new Flowlayout(this));
	addlayout(new Gridlayout(this,3));

	layout_->doLayout(width_,height_);//레이아웃 조정
	repaint();
	display->repaint();
	tbar->repaint();

}
void CalculateFrame::run() {

	//초기화
	initialize();
	//함수 처리
	repaint();
	Frame::run();
}
Window* CalculateFrame::findButton(int x, int y) {
	//해당되는 버튼 반환, 없으면 nullptr 반환
	for (auto win:mylist) {
		if (win->belongs(x, y)) {
			return win;
		}
	}
	for (int i = 17; i < 19; i++) {
		if (but[i]->belongs(x, y)) {
			return but[i];
		}
	}
	return nullptr;
}
bool CalculateFrame::processMessage(MyEvent e) {
	//frame에서 처리...?
	if (!Container::processMessage(e)) {
		switch (e.message_) {
		case WM_LBUTTONDOWN:
		{
			prev_ = findButton(e.x_, e.y_);
		}
		break;
		case WM_LBUTTONUP:
		{
			next_ = findButton(e.x_, e.y_);
			//눌린 버튼 출력
			char buf[128];
			sprintf_s(buf, " down: %d, up: %d\n", prev_->getcode(), next_->getcode());
			OutputDebugStringA(buf);

			if (prev_ == next_) {
				if (next_->getcode() < 10) {
					//업과 다운 버튼이 같고 정수이면
					InvalidateRect(hwnd_, NULL, true);
					display->setValue(next_->getcode());
				}
				else if (next_->getcode() >= 10 && next_->getcode() < 14) {
					//사칙 연산
					//value 초기화->real value로 넘기기
					InvalidateRect(hwnd_, NULL, true);
					display->save();
					display->remove();
					//어떤 모드인지 저장
					display->setcode(next_->getcode());
				}
				else if (next_->getcode() == 14) {
					//=
					InvalidateRect(hwnd_, NULL, true);
					display->calculate();
					display->repaint();
				}
				else if (next_->getcode() == 15) {
					//clear
					//value 초기화
					InvalidateRect(hwnd_, NULL, true);
					display->remove();
				}
				else if (next_->getcode() == 16) {
					//소수점 처리
					display->dot();
				}
				else if (next_->getcode() == 17&&display->mode==1) {
					//모드 바꿔주기
					display->changeMode();
				}
				else if (next_->getcode() == 18 && display->mode == 0) {
					//모드 바꿔주기
					display->changeMode();
				}
			}
		}

		break;
		
		case WM_PAINT:
		{
			//그려주기
			this->repaint();
			display->repaint();
			tbar->repaint();

		}
		break;

		case WM_SIZE:
		{
			RECT rect;
			GetClientRect(hwnd_, &rect);
			//창 크기 구하기
			width_ = rect.right - rect.left;
			height_ = rect.bottom - rect.top;
			//레이아웃이 존재하면 버튼 조정해주기
			if (layout_) {
				layout_->doLayout(width_, height_);
			}
			//다시 그리기
			this->repaint();
			tbar->repaint();
		}
		}
	}
	return true;
}