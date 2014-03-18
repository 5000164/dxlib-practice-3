#include "../Header/rendering.h"

namespace rendering {

void Rendering::BattleMenu(int command_selector, std::string menu1, std::string menu2) {
  font::Font font;

  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();
  font.Draw(menu1, 50, 50);
  font.Draw(menu2, 50, 100);

  if (command_selector == 1) {
    int color_dx = GetColor(230, 230, 230);
    DrawTriangle(35, 49, 35, 69, 45, 59, color_dx, FALSE);
  } else if (command_selector == 2) {
    int color_dx = GetColor(230, 230, 230);
    DrawTriangle(35, 99, 35, 119, 45, 109, color_dx, FALSE);
  }

  ScreenFlip();

  return;
}

void Rendering::BattleMessage(int command_selector, std::string message_text1, std::string c1_hit_point, std::string message_text2, std::string c2_hit_point) {
  font::Font font;

  if (command_selector == 1) {
    int color_dx = GetColor(230, 230, 230);
    DrawTriangle(35, 49, 35, 69, 45, 59, color_dx, FALSE);
  } else if (command_selector == 2) {
    int color_dx = GetColor(230, 230, 230);
    DrawTriangle(35, 99, 35, 119, 45, 109, color_dx, FALSE);
  }

  SetDrawScreen(DX_SCREEN_FRONT);
  font.Draw(message_text1, 100, 150);
  font.Draw(message_text2, 100, 180);
  font.Draw(c1_hit_point, 250, 150);
  font.Draw(c2_hit_point, 250, 180);

  return;
}

}
