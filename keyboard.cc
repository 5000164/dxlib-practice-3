#include "keyboard.h"
#include "dx_lib_wrapper.h"

void Keyboard::InputOnce(DxLibWrapper &dxlib)
{
	// キーがなにも押されていない状態になるまで進まない
	while (CheckHitKeyAll() != 0)
	{
		dxlib.SystemWatch();
	}

	// キーがなにか押されている状態になるまで進まない
	while (CheckHitKeyAll() == 0)
	{
		dxlib.SystemWatch();
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
