#ifndef character_h
#define character_h

#include <string>

class Character {
	int attack_point;
public:
	int hit_point;
	std::string action_list[2];
	Character(int, int);
	void Action(int, Character *);
	void Attack(Character *);
};

#endif
