#include "Gridlayout.h"
Gridlayout::Gridlayout(Frame* f, int row) 
	:Layout(f)
{
	//myFrame = f;
	row_ = row;
}
void Gridlayout::doLayout(int w, int h) {
	Layout::doLayout(w, h);
	for (auto win : myFrame->getList()) {
		//��ư�� �� ĭ�� �����ϴ��� ���ϱ�
		for (int a = 0; a < row_; a++) {
			if (win->size < width / row_ * a) {
				size_num = a;
				break;
			}
		}
		if (tempw + win->size <= width) {
			//���� �ȿ� ������
			//�״�� ����
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += width / row_ * (size_num);
		}
		else {
			//������ �����
			//tempw,temph �����ϰ�
			//�ٽ� ����
			tempw = 0;
			temph += 100;
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += width / row_ * (size_num);
		}
	}
	//�� �� ������ ������ �ʱ�ȭ
	tempw = 0;
	temph = 50;
}