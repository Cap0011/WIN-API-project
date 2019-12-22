#include "CalculateFrame.h"
#include "Flowlayout.h"
#include "Gridlayout.h"
#include "TextButton.h"
#include "RadioGroup.h"
#include "RadioButton.h"
#include "CheckBox.h"
//������
CalculateFrame::CalculateFrame(std::wstring title, int width, int height) : Frame(title, width, height) {
	//EMPTY.
}
CalculateFrame::CalculateFrame(std::wstring w)
	: Frame(w, 1000, 800)
{
	//EMPTY.
}
void CalculateFrame::initialize() {
	//���� �߰�
	tbar = new ToolBar();
	//RadioGroup �߰�(���ٿ� �Ҽӽ�Ű��)
	RadioGroup* rgroup = new RadioGroup();
	tbar->Add((Window*)rgroup);
	//���÷��� �߰�
	display = new TextLabel(hdc_, 50, 450, 500, 550, "display");

	//���� ��ư �߰�
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
	but[17] = new RadioButton(hdc_, 0, 0, 100, 50, "����");
	but[18] = new RadioButton(hdc_, 100, 0, 200, 50, "�Ǽ�");
	but[19] = new CheckBox(hdc_, 200, 0, 300, 50, "���� ���߱�� üũ �ڽ�");
	but[17]->setcode(17);
	but[18]->setcode(18);
	but[19]->setcode(19);
	tbar->Add(but[19]);
	//RadioGroup�� ��ư �߰�
	rgroup->Add((RadioButton*)but[17]);
	rgroup->Add((RadioButton*)but[18]);
	rgroup->repaint();
	//���� ����Ʈ�� �߰����ֱ�
	for (int i = 0; i < 17; i++) {
		Add(but[i]);
		but[i]->setcode(button_num);
		button_num++;
	}
	addLabel(display);

	//addlayout(new Flowlayout(this));
	addlayout(new Gridlayout(this,3));

	layout_->doLayout(width_,height_);//���̾ƿ� ����
	repaint();
	display->repaint();
	tbar->repaint();

}
void CalculateFrame::run() {

	//�ʱ�ȭ
	initialize();
	//�Լ� ó��
	repaint();
	Frame::run();
}
Window* CalculateFrame::findButton(int x, int y) {
	//�ش�Ǵ� ��ư ��ȯ, ������ nullptr ��ȯ
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
	//frame���� ó��...?
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
			//���� ��ư ���
			char buf[128];
			sprintf_s(buf, " down: %d, up: %d\n", prev_->getcode(), next_->getcode());
			OutputDebugStringA(buf);

			if (prev_ == next_) {
				if (next_->getcode() < 10) {
					//���� �ٿ� ��ư�� ���� �����̸�
					InvalidateRect(hwnd_, NULL, true);
					display->setValue(next_->getcode());
				}
				else if (next_->getcode() >= 10 && next_->getcode() < 14) {
					//��Ģ ����
					//value �ʱ�ȭ->real value�� �ѱ��
					InvalidateRect(hwnd_, NULL, true);
					display->save();
					display->remove();
					//� ������� ����
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
					//value �ʱ�ȭ
					InvalidateRect(hwnd_, NULL, true);
					display->remove();
				}
				else if (next_->getcode() == 16) {
					//�Ҽ��� ó��
					display->dot();
				}
				else if (next_->getcode() == 17&&display->mode==1) {
					//��� �ٲ��ֱ�
					display->changeMode();
				}
				else if (next_->getcode() == 18 && display->mode == 0) {
					//��� �ٲ��ֱ�
					display->changeMode();
				}
			}
		}

		break;
		
		case WM_PAINT:
		{
			//�׷��ֱ�
			this->repaint();
			display->repaint();
			tbar->repaint();

		}
		break;

		case WM_SIZE:
		{
			RECT rect;
			GetClientRect(hwnd_, &rect);
			//â ũ�� ���ϱ�
			width_ = rect.right - rect.left;
			height_ = rect.bottom - rect.top;
			//���̾ƿ��� �����ϸ� ��ư �������ֱ�
			if (layout_) {
				layout_->doLayout(width_, height_);
			}
			//�ٽ� �׸���
			this->repaint();
			tbar->repaint();
		}
		}
	}
	return true;
}