#ifndef rendering_h
#define rendering_h

#include <string>
#include "../Library/DxLib/DxLib.h"
#include "./font.h"

namespace rendering {

class Rendering {
public:
  void BattleMenu(int, std::string, std::string);
  void BattleMessage(int, std::string, std::string, std::string, std::string);
};

}

#endif
