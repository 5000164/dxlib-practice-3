#ifndef battle_h
#define battle_h

#include "character.h"

class Battle {
public:
	Battle();
	void Start(Character &, Character &);
	void End();
	void Command(int, Character &, Character &);
	void Menu(int);
};

#endif
