#include "keyboard.h"
#include "dx_lib.h"

void Keyboard::OnceInput()
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
