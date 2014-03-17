#include "../Header/window.h"

Window::Window()
{
  // 背景色設定
  int r = 30;
  int g = 30;
  int b = 30;

  int font_size = 18;
  font_family = "ＭＳ Ｐゴシック";
}

Window::~Window()
{
  // DXライブラリ使用終了処理
  DxLib_End();
}

void Window::Init()
{
  // ウィンドウで実行
  ChangeWindowMode(TRUE);

  // 1024x768px、32bitで実行
  SetGraphMode(1024, 768, 32);

  // 異常処理で強制終了
  if (DxLib_Init() == -1)
  {
    // DXライブラリ使用終了処理
    DxLib_End();

    exit(1);
  }

  SetBackgroundColor(r, g, b);

  // フォント変更は処理が重いのでウィンドウ毎に変更
  ChangeFont(font_family.c_str());
  SetFontSize(font_size);
  ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}
