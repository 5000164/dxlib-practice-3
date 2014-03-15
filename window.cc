#include "window.h"
#include <string>
#include "dx_lib_wrapper.h"

Window::Window()
{
	int r = 30;
	int g = 30;
	int b = 30;
	SetBackgroundColor(r, g, b);

	// �t�H���g�ύX�͏������d���̂ŃE�B���h�E���ɕύX
	std::string font_family = "�l�r �o�S�V�b�N";
	int font_size = 18;
	ChangeFont(font_family.c_str());
	SetFontSize(font_size);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}

Window::Window(int r, int g, int b)
{
	SetBackgroundColor(r, g, b);

	// �t�H���g�ύX�͏������d���̂ŃE�B���h�E���ɕύX
	std::string font_family = "�l�r �o�S�V�b�N";
	int font_size = 18;
	ChangeFont(font_family.c_str());
	SetFontSize(font_size);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}

Window::Window(int r, int g, int b, std::string font_family, int font_size)
{
	SetBackgroundColor(r, g, b);

	// �t�H���g�ύX�͏������d���̂ŃE�B���h�E���ɕύX
	ChangeFont(font_family.c_str());
	SetFontSize(font_size);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}
