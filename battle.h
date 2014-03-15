#ifndef battle_h
#define battle_h

#include "character.h"

class Battle {
public:
	void Start(Character &, Character &);
	void End();
	void Menu(int);
	int Command(int, Character &, Character &);
};

#endif
