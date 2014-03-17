#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/character.h"
#include "../Header/battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  // 表示初期化
  Window *window = new Window();
  window->Init();

  // キャラクター作成
  Character *character1 = new Character(10, 2, 5);
  character1->Init();
  Character *character2 = new Character(5, 3, 8);
  character2->Init();

  // デモバトル開始
  Battle *demo_battle = new Battle(character1, character2);
  demo_battle->Init();
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;

  // 表示終了
  delete window;

  return 0;
}
