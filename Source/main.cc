#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/character.h"
#include "../Header/battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
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

  // 表示初期化
  Window *window = new Window();

  // キャラクター作成
  Character *character1 = new Character(10, 2);
  Character *character2 = new Character(5, 3);

  // デモバトル開始
  Battle *demo_battle = new Battle(character1, character2);
  demo_battle->Init();
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;
  delete window;

  // DXライブラリ使用終了処理
  DxLib_End();

  return 0;
}
