#ifndef battle_h
#define battle_h

#include "dx_lib_wrapper.h"
#include "character.h"

class Battle {
public:
	void Start(DxLibWrapper &, Character &, Character &);
	void End();
	void Menu(int);
	int Command(int, Character &, Character &);
};

#endif
