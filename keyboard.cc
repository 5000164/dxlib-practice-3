#include "keyboard.h"
#include "dx_lib_wrapper.h"

void Keyboard::InputOnce()
{
	// �L�[���Ȃɂ�������Ă��Ȃ���ԂɂȂ�܂Ői�܂Ȃ�
	while (ProcessMessage() == 0 && CheckHitKeyAll() != 0)
	{
		// �L�[���Ȃɂ�������Ă���Ԃ̓��[�v
	}

	// �L�[���Ȃɂ�������Ă����ԂɂȂ�܂Ői�܂Ȃ�
	while (ProcessMessage() == 0 && CheckHitKeyAll() == 0)
	{
		// �L�[���Ȃɂ�������Ă��Ȃ��Ԃ̓��[�v
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
