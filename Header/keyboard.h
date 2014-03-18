#ifndef keyboard_h
#define keyboard_h

#include "../Library/DxLib/DxLib.h"
#include "./system.h"

namespace keyboard {

class Keyboard {
public:
  void InputOnce();
  bool IsPressEsc();
  bool IsPressReturn();
  bool IsPressUp();
  bool IsPressDown();
};

}

#endif
