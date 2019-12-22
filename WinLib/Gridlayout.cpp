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
		//버튼이 몇 칸을 차지하는지 구하기
		for (int a = 0; a < row_; a++) {
			if (win->size < width / row_ * a) {
				size_num = a;
				break;
			}
		}
		if (tempw + win->size <= width) {
			//범위 안에 들어오면
			//그대로 세팅
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += width / row_ * (size_num);
		}
		else {
			//범위를 벗어나면
			//tempw,temph 갱신하고
			//다시 세팅
			tempw = 0;
			temph += 100;
			win->setl(tempw);
			win->sett(temph);
			win->setr(tempw + win->size);
			win->setb(temph + 100);
			tempw += width / row_ * (size_num);
		}
	}
	//한 번 정렬이 끝나면 초기화
	tempw = 0;
	temph = 50;
}