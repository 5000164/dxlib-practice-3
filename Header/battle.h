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
  int SelectPhase(int);
  int ActionPhase(int);

  std::string message1;
  std::string message2;
  std::string message3;
  std::string message4;

private:
  Character *c1;
  Character *c2;
};

#endif
