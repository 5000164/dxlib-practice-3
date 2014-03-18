#ifndef font_h
#define font_h

#include <string>
#include "../Library/DxLib/DxLib.h"

namespace font {

class Font {
public:
  Font();
  void Draw(std::string, int, int);

private:
  int font_color[3];
  int font_color_dx;
  double line_height;
  int shadow_color[3];
  int shadow_color_dx;
  int shadow_position[2];
};

}

#endif
