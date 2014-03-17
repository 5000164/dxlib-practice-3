#ifndef window_h
#define window_h

#include <string>
#include "../Library/DxLib/DxLib.h"

class Window {
public:
  Window();
  ~Window();
  void Init();

private:
  int r;
  int g;
  int b;
  int font_size;
  std::string font_family;
};

#endif
