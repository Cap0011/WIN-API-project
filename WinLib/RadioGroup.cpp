#include "RadioGroup.h"
#include "RadioButton.h"
RadioGroup::RadioGroup(){
}
void RadioGroup::Add(RadioButton* rb) {
	b_list.push_back(rb);
	//rb->setcode(num_rb);
	//num_rb++;
}
void RadioGroup::repaint() {
	for (auto bt : b_list) {
		bt->repaint();
	}
}