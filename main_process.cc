#include <fstream>
#include "dx_lib.h"
#include "forward_declaration.h"
#include "objects.h"
#include "picojson.h"



// メイン処理
void MainProcess()
{
	Json json;

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



	// テキスト表示開始位置
	int menu_text_position[2] = { 60, 20 };

	ClearDrawScreen();
	int position_1[2] = { 35, 20 };
	int position_2[2] = { 35, 40 };
	int position_3[2] = { 45, 30 };
	int color[3] = { 230, 230, 230 };
	selector.Draw(position_1, position_2, position_3, color);
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

			int position_1[2] = { 35, 20 };
			int position_2[2] = { 35, 40 };
			int position_3[2] = { 45, 30 };
			int color[3] = { 230, 230, 230 };
			selector.Draw(position_1, position_2, position_3, color);
			ScreenFlip();
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// 方向キー下：下に移動
			menu_selector = 1;

			int position_1[2] = { 35, 51 };
			int position_2[2] = { 35, 71 };
			int position_3[2] = { 45, 61 };
			int color[3] = { 230, 230, 230 };
			selector.Draw(position_1, position_2, position_3, color);
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
	if (menu_selector == 0)
	{
		ClearDrawScreen();
		char text[256][256] = { "たたかった" };
		int position[2] = { 50, 50 };
		font.Draw(text, 1, position);
		ScreenFlip();
	}
	else if (menu_selector == 1)
	{
		ClearDrawScreen();
		char text[256][256] = { "逃げた" };
		int position[2] = {50, 50};
		font.Draw(text, 2, position);
		ScreenFlip();
	}
}
