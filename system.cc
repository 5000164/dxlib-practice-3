#include "system.h"
#include "dx_lib_wrapper.h"

void System::Watch()
{
	// �ُ폈���ŋ����I��
	if (ProcessMessage() == -1)
	{
		// DX���C�u�����g�p�I������
		DxLib_End();

		exit(1);
	}

	return;
}
