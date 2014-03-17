#ifndef character_h
#define character_h

#include <string>
#include "./json.h"

class Character {
public:
  Character(int, int);
  void Action(int, Character *);
  void Attack(Character *);

  int hit_point;
  std::string action_list[2];

private:
  int attack_point;
};

#endif
