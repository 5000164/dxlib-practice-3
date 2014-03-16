#include "window.h"
#include <string>
#include "dx_lib_wrapper.h"

Window::Window()
{
  // 背景色設定
  int r = 30;
  int g = 30;
  int b = 30;
  SetBackgroundColor(r, g, b);

  // フォント変更は処理が重いのでウィンドウ毎に変更
  std::string font_family = "ＭＳ Ｐゴシック";
  int font_size = 18;
  ChangeFont(font_family.c_str());
  SetFontSize(font_size);
  ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}
