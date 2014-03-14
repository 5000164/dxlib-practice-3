#include "battle.h"
#include <string>
#include "dx_lib.h"
#include "picojson.h"
#include "font.h"
#include "selector.h"
#include "json.h"


Battle::Battle(Font font, Selector selector)
{
	this->font = font;
	this->selector = selector;
}

void Battle::Start()
{
	Json text_json("text.json");

	picojson::array array = text_json.GetArray("menu");

	std::string menu_text[2];
	int count = 0;
	for (picojson::array::iterator i = array.begin(); i != array.end(); i++) {
		menu_text[count] = i->get<std::string>();
		count++;
	}

	// ‰æ–Ê•`‰æ
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	font.Draw(menu_text[0], 50, 50);
	font.Draw(menu_text[1], 50, 100);
	selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
	ScreenFlip();
}

void Battle::End()
{

}

void Battle::Command(int command_id)
{
	Json text_json("text.json");

	if (command_id == 0)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = text_json.GetString("battle");
		font.Draw(string, 100, 150);
	}
	else if (command_id == 1)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = text_json.GetString("escape");
		font.Draw(string, 100, 150);
	}
}

void Battle::Menu(int menu_id)
{
	Json text_json("text.json");

	picojson::array array = text_json.GetArray("menu");

	std::string menu_text[2];
	int count = 0;
	for (picojson::array::iterator i = array.begin(); i != array.end(); i++) {
		menu_text[count] = i->get<std::string>();
		count++;
	}

	if (menu_id == 0)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		font.Draw(menu_text[0], 50, 50);
		font.Draw(menu_text[1], 50, 100);
		selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
		ScreenFlip();
	}
	else if (menu_id == 1)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		font.Draw(menu_text[0], 50, 50);
		font.Draw(menu_text[1], 50, 100);
		selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
		ScreenFlip();
	}
}