#include "../Header/rendering.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/font.h"

namespace rendering {

void Rendering::Battle(battle::Battle *battle) {
  font::Font *font = new font::Font();

  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();

  font->Draw(battle->c1->action_list1, 50, 50);
  font->Draw(battle->c1->action_list2, 50, 100);
  if (battle->action_id == 1) {
    DrawTriangle(35, 49, 35, 69, 45, 59, font->font_color_dx, FALSE);
  } else {
    DrawTriangle(35, 99, 35, 119, 45, 109, font->font_color_dx, FALSE);
  }
  font->Draw(battle->message3, 100, 150);
  font->Draw(battle->message4, 100, 180);
  font->Draw(std::to_string(battle->c1->hit_point), 250, 150);
  font->Draw(std::to_string(battle->c2->hit_point), 250, 180);

  ScreenFlip();

  return;
}

}
