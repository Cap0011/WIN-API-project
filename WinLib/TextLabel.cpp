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
	//�� �������ֱ�
	if (mode == 0) {
		//����
		value_ = value_ * 10 + n;
	}
	else {
		//�Ǽ�
		if (isDot) {
			//�Ҽ��� �ڸ�
			fvalue_ += dividen * n;
			dividen /= 10;
		}
		else {
			fvalue_ = fvalue_ * 10 + n;
		}
	}
}
void TextLabel::repaint() {
	//�ش� ��ư�� �׸���.
	::Rectangle(hdc_, left_, top_, right_, bottom_);
	//�ؽ�Ʈ�� �׸���.
	TCHAR str[128] = { 0, };
	if (mode == 0) {
		//����
		wsprintf(str, TEXT("%ld"), value_);
		TextOut(hdc_, left_ + 30, top_ + 30, str, lstrlen(str));
	}
	else {
		//�Ǽ�
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
			//����
			value_ = value_ + real_value_;
		}
		else if (code == 11) {
			//����
			value_ = real_value_ - value_;
		}
		else if (code == 12) {
			//����
			value_ *= real_value_;
		}
		else if (code == 13) {
			//������
			value_ = real_value_ / value_;
		}
		char buf[128];
		sprintf_s(buf, "���� %lld", value_);
		OutputDebugStringA(buf);
	}
	else {
		if (code == 10) {
			//����
			fvalue_ = fvalue_ + freal_value_;
		}
		else if (code == 11) {
			//����
			fvalue_ = freal_value_ - fvalue_;
		}
		else if (code == 12) {
			//����
			fvalue_ *= freal_value_;
		}
		else if (code == 13) {
			//������
			fvalue_ = freal_value_ / fvalue_;
		}
		char buf[128];
		sprintf_s(buf, "���� %f", fvalue_);
		OutputDebugStringA(buf);
	}

}
void TextLabel::dot() {
	//�Ǽ� ����϶��� ó��
	if (mode == 1) {
		isDot = true;
	}
}