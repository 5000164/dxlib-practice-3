#include "dx_lib_wrapper.h"

DxLibWrapper::DxLibWrapper()
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
}

DxLibWrapper::~DxLibWrapper()
{
	// DXライブラリ使用終了処理
	DxLib_End();
}

void DxLibWrapper::SystemWatch()
{
	// 異常処理で強制終了
	if (ProcessMessage() == -1)
	{
		// DXライブラリ使用終了処理
		DxLib_End();

		exit(1);
	}

	return;
}
