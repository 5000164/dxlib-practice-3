#ifndef battle_h
#define battle_h

#include <string>
#include "./system.h"
#include "./rendering.h"
#include "./json.h"
#include "./keyboard.h"
#include "./character.h"

class Battle {
public:
  Battle(Character *, Character *);
  ~Battle();
  void Init();
  void Run();

  std::string battle_message[4];

private:
  Character *c1;
  Character *c2;
};

#endif
