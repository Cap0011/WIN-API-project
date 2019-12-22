#include "frame.h"
#include "CalculateFrame.h"
#include <iostream>
int main() {
	try {
		Frame* win = new CalculateFrame(L"ป๙วร");
		win->run();
	}
	catch (int n) {
		std::cerr << "Error" << std::endl;
	}
}