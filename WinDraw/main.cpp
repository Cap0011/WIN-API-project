#include "frame.h"
#include "DrawFrame.h"
#include <iostream>
int main() {
	try {
		Frame* win = new DrawFrame(L"�׸���");
		win->run();
	}
	catch (int n) {
		std::cerr << "Error" << std::endl;
	}
}