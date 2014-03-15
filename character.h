#ifndef character_h
#define character_h

#include <string>

class Character {
	int attack_point;
public:
	int hit_point;
	Character(int, int);
	void Attack(Character &);
};

#endif
