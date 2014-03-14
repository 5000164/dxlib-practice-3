#ifndef battle_h
#define battle_h

#include "font.h"
#include "selector.h"

class Battle {
	Font font;
	Selector selector;
public:
	Battle(Font, Selector);
	void Start();
	void End();
	void Command(int);
	void Menu(int);
};

#endif
