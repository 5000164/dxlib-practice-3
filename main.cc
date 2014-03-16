#include "dx_lib_wrapper.h"
#include "window.h"
#include "character.h"
#include "battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  // 表示初期化
  DxLibWrapper *dxlib = new DxLibWrapper();
  Window *window = new Window();

  // キャラクター作成
  Character *character1 = new Character(10, 2);
  Character *character2 = new Character(5, 3);

  // デモバトル開始
  Battle *demo_battle = new Battle(character1, character2);
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;
  delete window;
  delete dxlib;

  return 0;
}
