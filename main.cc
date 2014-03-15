#include "dx_lib.h"
#include "window.h"
#include "font.h"
#include "keyboard.h"
#include "selector.h"
#include "character.h"
#include "battle.h"

void MainProcess()
{
	// 表示初期化
	Window window;

	// キャラクター作成
	Character character1(10, 2);
	Character character2(5, 3);

	// デモバトル開始
	Battle demo_battle;
	demo_battle.Start(character1, character2);

	return;
}
