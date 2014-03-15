#include "dx_lib_wrapper.h"

void DxLibWrapper::SystemWatch()
{
	if (ProcessMessage() == -1)
	{
		// DXライブラリ使用終了処理
		DxLib_End();

		exit(1);
	}

	return;
}
