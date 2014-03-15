#include "battle.h"
#include <string>
#include "dx_lib.h"
#include "picojson.h"
#include "json.h"
#include "font.h"
#include "selector.h"
#include "keyboard.h"
#include "character.h"

Battle::Battle()
{
}

void Battle::Start(Character &c1, Character &c2)
{
	// メニュー表示
	this->Menu(1);

	///
	/// ループ処理
	///

	Keyboard keyboard;

	// 選択しているメニュー
	int command_selector = 1;

	bool loop_flag = true;

	// Escキーの入力でゲーム終了
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && loop_flag)
	{
		// キーボードの入力待ち
		keyboard.OnceInput();

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			this->Menu(command_selector);
			int result = this->Command(command_selector, c1, c2);

			if (result == 2)
			{
				// バトル終了
				loop_flag = false;
			}
		}
		else if (CheckHitKey(KEY_INPUT_UP))
		{
			command_selector = 1;
			this->Menu(command_selector);
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			command_selector = 2;
			this->Menu(command_selector);
		}
	}

	this->End();
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

	// 画面描画
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

int Battle::Command(int command_selector, Character &c1, Character &c2)
{
	int result;
	Font font;
	Selector selector;

	// たたかう
	if (command_selector == 1)
	{
		c1.Attack(c2);
		c2.Attack(c1);
		selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
		result = 1;
	}
	// にげる
	else if (command_selector == 2)
	{
		selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
		result = 2;
	}

	SetDrawScreen(DX_SCREEN_FRONT);

	Json battle_result("battle__result.json");
	std::string result_text = battle_result.GetString(std::to_string(result));
	font.Draw(result_text, 100, 150);

	Json battle_message("battle__message.json");
	std::string message_text1 = battle_message.GetString("1");
	std::string message_text2 = battle_message.GetString("2");
	font.Draw(message_text1, 100, 180);
	font.Draw(message_text2, 100, 210);
	font.Draw(std::to_string(c1.hit_point), 250, 180);
	font.Draw(std::to_string(c2.hit_point), 250, 210);

	return result;
}
