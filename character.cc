#include "character.h"

Character::Character(int hit_point, int attack_point)
{
	this->hit_point = hit_point;
	this->attack_point = attack_point;
}

void Character::Attack(Character &target)
{
	target.hit_point = target.hit_point - this->attack_point;
}
