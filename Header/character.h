#ifndef character_h
#define character_h

#include <string>
#include "./json.h"

namespace character {

class Character {
public:
  Character(int, int, int);
  void Init();
  bool IsFasterThan(Character *);
  void Action(int, Character *);

  int hit_point;
  std::string action_list1;
  std::string action_list2;

private:
  void Attack(Character *);

  int attack_point;
  int speed;
};

}

#endif
