#include "dx_lib_wrapper.h"
#include "window.h"
#include "character.h"
#include "battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 表示初期化
	DxLibWrapper dxlib;
	Window window;

	// キャラクター作成
	Character character1(10, 2);
	Character character2(5, 3);

	// デモバトル開始
	Battle demo_battle;
	demo_battle.Start(dxlib, character1, character2);

	return 0;
}
