#include "keyboard.h"
#include "dx_lib_wrapper.h"

void Keyboard::InputOnce()
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

bool Keyboard::IsPressEsc()
{
	bool result = false;

	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		result = true;
	}

	return result;
}

bool Keyboard::IsPressReturn()
{
	bool result = false;

	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		result = true;
	}

	return result;
}

bool Keyboard::IsPressUp()
{
	bool result = false;

	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		result = true;
	}

	return result;
}

bool Keyboard::IsPressDown()
{
	bool result = false;

	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		result = true;
	}

	return result;
}
