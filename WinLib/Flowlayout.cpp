#include "Flowlayout.h"
Flowlayout::Flowlayout(Frame* f) 
	:Layout(f)
{
}
void Flowlayout::doLayout(int w,int h) {
	Layout::doLayout(w,h);
	
	for (auto win : myFrame->getList()) {
		if (tempw + win->size <= width) {
			//범위 안에 들어오면
			//그대로 세팅
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw+win->size);
			win->setb(temph + 100);
			tempw += win->getsize();
		}
		else {
			//범위를 벗어나면
			//tempw,temph 갱신하고
			tempw = 0;
			temph += 100;
			//다시 세팅
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += win->getsize();
		}
	}
	//한 번 정렬이 끝나면 초기화
	tempw = 0;
	temph = 50;
}