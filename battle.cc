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
	// ���j���[�\��
	this->Menu(1);

	Keyboard keyboard;
	int command_selector = 1;
	bool end_flag = false;

	// Esc�L�[�̓��͂ŃQ�[���I��
	while (!(keyboard.IsPressEsc() || end_flag))
	{
		// �L�[�{�[�h�̓��͑҂�
		keyboard.InputOnce(dxlib);

		if (keyboard.IsPressReturn())
		{
			// ���j���[�\��
			this->Menu(command_selector);
			int result = this->Command(command_selector, c1, c2);

			if (result == 2)
			{
				// �o�g���I��
				end_flag = true;
			}
		}
		else if (keyboard.IsPressUp())
		{
			command_selector = 1;

			// ���j���[�\��
			this->Menu(command_selector);
		}
		else if (keyboard.IsPressDown())
		{
			command_selector = 2;

			// ���j���[�\��
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
	// ���j���[���ڎ擾
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

	// ��������
	if (command_selector == 1)
	{
		c1.Attack(c2);
		c2.Attack(c1);
		result = 1;
	}
	// �ɂ���
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
