#include "Flowlayout.h"
Flowlayout::Flowlayout(Frame* f) 
	:Layout(f)
{
}
void Flowlayout::doLayout(int w,int h) {
	Layout::doLayout(w,h);
	
	for (auto win : myFrame->getList()) {
		if (tempw + win->size <= width) {
			//���� �ȿ� ������
			//�״�� ����
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw+win->size);
			win->setb(temph + 100);
			tempw += win->getsize();
		}
		else {
			//������ �����
			//tempw,temph �����ϰ�
			tempw = 0;
			temph += 100;
			//�ٽ� ����
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += win->getsize();
		}
	}
	//�� �� ������ ������ �ʱ�ȭ
	tempw = 0;
	temph = 50;
}