#include "TextLabel.h"
TextLabel::TextLabel(HDC hdc, int l, int t, int r, int b, std::string title)
	:TButton(hdc, l, t, r, b, title)
{
	size = 300;
}
void TextLabel::changeMode() {
	if (mode == 0) {
		mode = 1;
	}
	else {
		mode = 0;
	}
}
void TextLabel::setValue(int n) {
	//°ª °»½ÅÇØÁÖ±â
	if (mode == 0) {
		//Á¤¼ö
		value_ = value_ * 10 + n;
	}
	else {
		//½Ç¼ö
		if (isDot) {
			//¼Ò¼öÁ¡ µÚ¸é
			fvalue_ += dividen * n;
			dividen /= 10;
		}
		else {
			fvalue_ = fvalue_ * 10 + n;
		}
	}
}
void TextLabel::repaint() {
	//ÇØ´ç ¹öÆ°À» ±×¸°´Ù.
	::Rectangle(hdc_, left_, top_, right_, bottom_);
	//ÅØ½ºÆ®¸¦ ±×¸°´Ù.
	TCHAR str[128] = { 0, };
	if (mode == 0) {
		//Á¤¼ö
		wsprintf(str, TEXT("%ld"), value_);
		TextOut(hdc_, left_ + 30, top_ + 30, str, lstrlen(str));
	}
	else {
		//½Ç¼ö
		char temp[128] = {0,};
		sprintf_s(temp,"%lf", fvalue_);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, temp, strlen(temp), str, 256);
		TextOut(hdc_, left_ + 30, top_ + 30, str, lstrlen(str));
	}

}
void TextLabel::remove() {
	if (mode == 0) {
		value_ = 0;
	}
	else {
		fvalue_ = 0;
		dividen = 0.1;
		isDot = false;
	}
}
void TextLabel::save() {
	if (mode == 0) {
		real_value_ = value_;
	}
	else {
		freal_value_ = fvalue_;
	}
}
void TextLabel::calculate() {
	if (mode == 0) {
		if (code == 10) {
			//µ¡¼À
			value_ = value_ + real_value_;
		}
		else if (code == 11) {
			//»¬¼À
			value_ = real_value_ - value_;
		}
		else if (code == 12) {
			//°ö¼À
			value_ *= real_value_;
		}
		else if (code == 13) {
			//³ª´°¼À
			value_ = real_value_ / value_;
		}
		char buf[128];
		sprintf_s(buf, "°ªÀº %lld", value_);
		OutputDebugStringA(buf);
	}
	else {
		if (code == 10) {
			//µ¡¼À
			fvalue_ = fvalue_ + freal_value_;
		}
		else if (code == 11) {
			//»¬¼À
			fvalue_ = freal_value_ - fvalue_;
		}
		else if (code == 12) {
			//°ö¼À
			fvalue_ *= freal_value_;
		}
		else if (code == 13) {
			//³ª´°¼À
			fvalue_ = freal_value_ / fvalue_;
		}
		char buf[128];
		sprintf_s(buf, "°ªÀº %f", fvalue_);
		OutputDebugStringA(buf);
	}

}
void TextLabel::dot() {
	//½Ç¼ö ¸ðµåÀÏ¶§¸¸ Ã³¸®
	if (mode == 1) {
		isDot = true;
	}
}