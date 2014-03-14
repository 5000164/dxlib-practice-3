#include "dx_lib.h"
#include "picojson.h"

class Json {
public:
	std::string GetString(std::string, std::string);
	picojson::array GetArray(std::string, std::string);
};

std::string Json::GetString(std::string file_name, std::string key)
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

	std::string string = o[key].get<std::string>();

	return string;
}

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
	void Draw(std::string, int, int);
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

void Font::Draw(std::string text, int x, int y)
{
	int len = text.length();
	char* text_chara = new char[len + 1];
	memcpy(text_chara, text.c_str(), len + 1);

	DrawString(x, y, text_chara, font_color_dx);
}



class Triangle {
	int color_dx;
public:
	Triangle();
	void Draw(int, int, int, int, int, int, int, int, int);
};

Triangle::Triangle()
{
}

void Triangle::Draw(int position_1_x, int position_1_y, int position_2_x, int position_2_y, int position_3_x, int position_3_y, int r, int g, int b)
{
	color_dx = GetColor(r, g, b);
	DrawTriangle(position_1_x, position_1_y, position_2_x, position_2_y, position_3_x, position_3_y, color_dx, FALSE);
}
