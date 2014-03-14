#include "dx_lib.h"
#include "picojson.h"

class Json {
public:
	picojson::array GetArray(std::string, std::string);
};

picojson::array Json::GetArray(std::string file_name, std::string key)
{
	std::string path = file_name;
	std::ifstream file;
	file.open(path.c_str());

	if (file.fail()) {
	}

	std::istreambuf_iterator<char> first(file);
	std::istreambuf_iterator<char> last;
	std::string json_str(first, last);

	picojson::value json;
	std::string err;
	picojson::parse(json, json_str.begin(), json_str.end(), &err);

	picojson::object &o = json.get<picojson::object>();

	picojson::array &array = o[key].get<picojson::array>();

	return array;
}



class Event {

};

class character {

};

class player {

};

class enemy {

};

















class Window {
	int background_color[3];
public:
	Window();
};

Window::Window()
{
	background_color[0] = 30;
	background_color[1] = 30;
	background_color[2] = 30;
	SetBackgroundColor(background_color[0], background_color[1], background_color[2]);
}



class Font {
	int font_size;
	int font_color[3];
	int font_color_dx;
	double line_height;
	int shadow_color[3];
	int shadow_color_dx;
	int shadow_position[2];
public:
	Font();
	void Draw(char[256][256], int, int[2]);
};

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

void Font::Draw(char text[256][256], int text_row, int position[2])
{
	int screen = MakeScreen(1024, 768, FALSE);
	SetDrawScreen(screen);
	ClearDrawScreen();

	// ‰e‚Ì•`‰æ
	for (int row = 0; row < text_row; row++)
	{
		int x = position[0] + shadow_position[0];
		int y = (int)(position[1] + ((font_size * line_height) * row) + shadow_position[1]);

		DrawString(x, y, text[row], shadow_color_dx);
	}

	GraphFilter(screen, DX_GRAPH_FILTER_GAUSS, 8, 50);



	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	DrawGraph(0, 0, screen, FALSE);

	// ƒeƒLƒXƒg‚Ì•`‰æ
	for (int row = 0; row < text_row; row++)
	{
		int x = position[0];
		int y = (int)(position[1] + ((font_size * line_height) * row));

		DrawString(x, y, text[row], font_color_dx);
	}
}



class Triangle {
	int color_dx;
public:
	Triangle();
	void Draw(int[2], int[2], int[2], int[3]);
};

Triangle::Triangle()
{
}

void Triangle::Draw(int position_1[2], int position_2[2], int position_3[2], int color[3])
{
	color_dx = GetColor(color[0], color[1], color[2]);
	DrawTriangle(position_1[0], position_1[1], position_2[0], position_2[1], position_3[0], position_3[1], color_dx, FALSE);
}
