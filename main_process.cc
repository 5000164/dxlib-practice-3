#include <fstream>
#include "dx_lib.h"
#include "forward_declaration.h"
#include "objects.h"
#include "picojson.h"



// メイン処理
void MainProcess()
{
	Json json;

	// メニュー文章読み込み
	picojson::array array = json.GetArray("text.json", "menu");

	std::string menu_text[2];
	int count = 0;
	for (picojson::array::iterator i = array.begin(); i != array.end(); i++) {
		menu_text[count] = i->get<std::string>();
		count++;
	}



	Window window;
	Font font;
	Triangle selector;


	// 画面描画
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	font.Draw(menu_text[0], 50, 50);
	font.Draw(menu_text[1], 50, 100);
	selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
	ScreenFlip();



	///
	/// ループ処理
	///

	// 選択しているメニュー
	int menu_selector = 0;

	// Escキーの入力でループ終了
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// キーボードの入力待ち
		OnceKeyInput();


		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			run(menu_selector);
		}
		else if (CheckHitKey(KEY_INPUT_UP))
		{
			// 方向キー上：上に移動
			menu_selector = 0;

			SetDrawScreen(DX_SCREEN_BACK);
			ClearDrawScreen();
			font.Draw(menu_text[0], 50, 50);
			font.Draw(menu_text[1], 50, 100);
			selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
			ScreenFlip();
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// 方向キー下：下に移動
			menu_selector = 1;

			SetDrawScreen(DX_SCREEN_BACK);
			ClearDrawScreen();
			font.Draw(menu_text[0], 50, 50);
			font.Draw(menu_text[1], 50, 100);
			selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
			ScreenFlip();
		}
	}



	///
	/// 終了処理
	///

	return;
}




///
/// キーの連続入力を防止する
///
void OnceKeyInput()
{
	// キーがなにも押されていない状態になるまで進まない
	while (ProcessMessage() == 0 && CheckHitKeyAll() != 0)
	{
		// キーがなにか押されている間はループ
	}

	// キーがなにか押されている状態になるまで進まない
	while (ProcessMessage() == 0 && CheckHitKeyAll() == 0)
	{
		// キーがなにも押されていない間はループ
	}

	return;
}



///
/// 実行
///
void run(int menu_selector)
{
	Font font;
	Json json;

	if (menu_selector == 0)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = json.GetString("text.json", "battle");
		font.Draw(string, 100, 150);
	}
	else if (menu_selector == 1)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = json.GetString("text.json", "escape");
		font.Draw(string, 100, 150);
	}
}
