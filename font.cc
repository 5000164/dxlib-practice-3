#include "font.h"
#include <string>
#include "dx_lib.h"

Font::Font()
{
	font_size = 18;
	font_color[0] = 230;
	font_color[1] = 230;
	font_color[2] = 230;
	line_height = 1.73;
	shadow_color[0] = 5;
	shadow_color[1] = 5;
	shadow_color[2] = 5;
	shadow_position[0] = 0;
	shadow_position[1] = 2;
	font_color_dx = GetColor(font_color[0], font_color[1], font_color[2]);
	shadow_color_dx = GetColor(shadow_color[0], shadow_color[1], shadow_color[2]);
	ChangeFont("‚l‚r ‚oƒSƒVƒbƒN");
	SetFontSize(font_size);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}

void Font::Draw(std::string text, int x, int y)
{
	int len = text.length();
	char* text_chara = new char[len + 1];
	memcpy(text_chara, text.c_str(), len + 1);

	DrawString(x, y, text_chara, font_color_dx);
}
