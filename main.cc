#include "dx_lib.h"
#include "window.h"
#include "font.h"
#include "keyboard.h"
#include "selector.h"
#include "battle.h"



// メイン処理
void MainProcess()
{
	// 表示初期化
	Window window;
	Font font;
	Keyboard key;
	Selector selector;



	// デモバトル開始
	Battle demo_battle(font, selector);
	demo_battle.Start();



	///
	/// ループ処理
	///

	// 選択しているメニュー
	int command_selector = 0;

	// Escキーの入力でループ終了
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// キーボードの入力待ち
		key.OnceInput();

		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			demo_battle.Command(command_selector);
		}
		else if (CheckHitKey(KEY_INPUT_UP))
		{
			command_selector = 0;
			demo_battle.Menu(command_selector);
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			command_selector = 1;
			demo_battle.Menu(command_selector);
		}
	}
	demo_battle.End();



	///
	/// 終了処理
	///

	return;
}
