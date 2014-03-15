#include "battle.h"
#include <string>
#include "dx_lib_wrapper.h"
#include "picojson.h"
#include "rendering.h"
#include "json.h"
#include "keyboard.h"
#include "character.h"

void Battle::Start(DxLibWrapper &dxlib, Character &c1, Character &c2)
{
	// メニュー表示
	this->Menu(1);

	Keyboard keyboard;
	int command_selector = 1;
	bool end_flag = false;

	// Escキーの入力でゲーム終了
	while (!(keyboard.IsPressEsc() || end_flag))
	{
		// キーボードの入力待ち
		keyboard.InputOnce(dxlib);

		if (keyboard.IsPressReturn())
		{
			// メニュー表示
			this->Menu(command_selector);
			int result = this->Command(command_selector, c1, c2);

			if (result == 2)
			{
				// バトル終了
				end_flag = true;
			}
		}
		else if (keyboard.IsPressUp())
		{
			command_selector = 1;

			// メニュー表示
			this->Menu(command_selector);
		}
		else if (keyboard.IsPressDown())
		{
			command_selector = 2;

			// メニュー表示
			this->Menu(command_selector);
		}

		dxlib.SystemWatch();
	}

	this->End();

	return;
}

void Battle::End()
{
	WaitTimer(1000);

	return;
}

void Battle::Menu(int command_selector)
{
	// メニュー項目取得
	Json battle_menu("battle__menu.json");
	std::string menu1 = battle_menu.GetString("1");
	std::string menu2 = battle_menu.GetString("2");

	Rendering rendering;
	rendering.BattleMenu(command_selector, menu1, menu2);

	return;
}

int Battle::Command(int command_selector, Character &c1, Character &c2)
{
	int result;

	// たたかう
	if (command_selector == 1)
	{
		c1.Attack(c2);
		c2.Attack(c1);
		result = 1;
	}
	// にげる
	else if (command_selector == 2)
	{
		result = 2;
	}

	Json battle_result("battle__result.json");
	std::string result_text = battle_result.GetString(std::to_string(result));

	Json battle_message("battle__message.json");
	std::string message_text1 = battle_message.GetString("1");
	std::string message_text2 = battle_message.GetString("2");

	Rendering rendering;
	rendering.BattleMessage(command_selector, result, result_text, message_text1, message_text2, std::to_string(c1.hit_point), std::to_string(c2.hit_point));

	return result;
}
