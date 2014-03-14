#include "keyboard.h"
#include "dx_lib.h"

void Keyboard::OnceInput()
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
