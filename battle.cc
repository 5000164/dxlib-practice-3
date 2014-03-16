#include "battle.h"
#include <string>
#include "system.h"
#include "rendering.h"
#include "json.h"
#include "keyboard.h"
#include "character.h"

Battle::Battle(Character *c1, Character *c2)
{
	this->c1 = c1;
	this->c2 = c2;

	// メッセージ読み込み
	Json battle_message("battle__message.json");
	this->battle_message[0] = battle_message.GetString("1");
	this->battle_message[1] = battle_message.GetString("2");
	this->battle_message[2] = battle_message.GetString("3");
	this->battle_message[3] = battle_message.GetString("4");
}

Battle::~Battle()
{
	WaitTimer(1000);
}

void Battle::Run()
{
	System *system = new System();
	Keyboard *keyboard = new Keyboard();
	Rendering *rendering = new Rendering();
	int action_id = 1;
	bool continuation_flag = true;

	while (continuation_flag)
	{
		rendering->BattleMenu(action_id, c1->action_list[0], c1->action_list[1]);
		rendering->BattleMessage(action_id, battle_message[2], std::to_string(c1->hit_point), battle_message[3], std::to_string(c2->hit_point));

		// キーボードの入力待ち
		keyboard->InputOnce();

		if (keyboard->IsPressReturn())
		{
			c1->Action(action_id, c2);

			rendering->BattleMessage(action_id, battle_message[2], std::to_string(c1->hit_point), battle_message[3], std::to_string(c2->hit_point));
			
			if (c1->hit_point <= 0 || c2->hit_point <= 0) {
				continuation_flag = false;
			}
		}
		else if (keyboard->IsPressUp())
		{
			action_id = 1;

			// メニュー表示
			rendering->BattleMenu(action_id, c1->action_list[0], c1->action_list[1]);
		}
		else if (keyboard->IsPressDown())
		{
			action_id = 2;

			// メニュー表示
			rendering->BattleMenu(action_id, c1->action_list[0], c1->action_list[1]);
		}

		system->Watch();
	}

	delete rendering;
	delete keyboard;
	delete system;

	return;
}
