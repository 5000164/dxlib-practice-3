#include "rendering.h"
#include <string>
#include "dx_lib_wrapper.h"
#include "font.h"
#include "selector.h"

Rendering::Rendering()
{
}

void Rendering::BattleMenu(int command_selector, std::string menu1, std::string menu2)
{
	// ‰æ–Ê•`‰æ
	Font font;
	Selector selector;
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	font.Draw(menu1, 50, 50);
	font.Draw(menu2, 50, 100);

	if (command_selector == 1)
	{
		selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
	}
	else if (command_selector == 2)
	{
		selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
	}

	ScreenFlip();
}

void Rendering::BattleMessage(int command_selector, int result, std::string result_text, std::string message_text1, std::string message_text2, std::string c1_hit_point, std::string c2_hit_point)
{
	Font font;
	Selector selector;

	// ‚½‚½‚©‚¤
	if (command_selector == 1)
	{
		selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
	}
	// ‚É‚°‚é
	else if (command_selector == 2)
	{
		selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
	}

	SetDrawScreen(DX_SCREEN_FRONT);
	font.Draw(result_text, 100, 150);
	font.Draw(message_text1, 100, 180);
	font.Draw(message_text2, 100, 210);
	font.Draw(c1_hit_point, 250, 180);
	font.Draw(c2_hit_point, 250, 210);
}
