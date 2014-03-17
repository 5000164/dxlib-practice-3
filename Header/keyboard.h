#ifndef keyboard_h
#define keyboard_h

#include "../Library/DxLib/DxLib.h"
#include "./system.h"

class Keyboard {
public:
  void InputOnce();
  bool IsPressEsc();
  bool IsPressReturn();
  bool IsPressUp();
  bool IsPressDown();
};

#endif
