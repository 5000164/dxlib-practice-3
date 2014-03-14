#include "dx_lib.h"
#include "window.h"
#include "font.h"
#include "keyboard.h"
#include "selector.h"
#include "battle.h"

void MainProcess()
{
	// 表示初期化
	Window window;

	// デモバトル開始
	Battle demo_battle;
	demo_battle.Start();

	return;
}
