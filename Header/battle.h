#ifndef battle_h
#define battle_h

#include <string>
#include "./character.h"

namespace battle {

class Battle {
public:
  Battle(character::Character *, character::Character *);
  ~Battle();
  void Init();
  void Run();
  void SelectPhase();
  void ActionPhase();

  std::string message1;
  std::string message2;
  std::string message3;
  std::string message4;
  character::Character *c1;
  character::Character *c2;
  int action_id;
  int action_result;
  bool continuation_flag;
};

}

#endif
