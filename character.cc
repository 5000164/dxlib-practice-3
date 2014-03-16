#include "character.h"
#include <string>
#include "json.h"

Character::Character(int hit_point, int attack_point)
{
	this->hit_point = hit_point;
	this->attack_point = attack_point;

	// 行動可能リスト読み込み
	Json battle_menu("character__action_list.json");
	this->action_list[0] = battle_menu.GetString("1");
	this->action_list[1] = battle_menu.GetString("2");
}

void Character::Action(int action_id, Character *target)
{
	if (action_id = 1)
	{
		this->Attack(target);
	}

	return;
}

void Character::Attack(Character *target)
{
	target->hit_point = target->hit_point - this->attack_point;

	return;
}
