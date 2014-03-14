#include "battle.h"
#include <string>
#include "dx_lib.h"
#include "picojson.h"
#include "font.h"
#include "selector.h"
#include "keyboard.h"
#include "json.h"

Battle::Battle()
{
}

void Battle::Start()
{
	// ���j���[�\��
	this->Menu(1);

	///
	/// ���[�v����
	///

	Keyboard keyboard;

	// �I�����Ă��郁�j���[
	int command_selector = 1;

	// Esc�L�[�̓��͂Ń��[�v�I��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �L�[�{�[�h�̓��͑҂�
		keyboard.OnceInput();

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			this->Command(command_selector);
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

	// �o�g���I��
	this->End();
}

void Battle::End()
{
}

void Battle::Menu(int command_selector)
{
	// ���j���[���ڎ擾
	Json battle_menu("battle__menu.json");
	std::string menu1 = battle_menu.GetString("1");
	std::string menu2 = battle_menu.GetString("2");

	// ��ʕ`��
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

void Battle::Command(int command_selector)
{
	Json battle_result("battle__result.json");

	SetDrawScreen(DX_SCREEN_FRONT);
	std::string command_selector_string = std::to_string(command_selector);
	std::string result = battle_result.GetString(command_selector_string);
	font.Draw(result, 100, 150);
}
