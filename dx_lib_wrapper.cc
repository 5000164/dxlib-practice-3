#include "dx_lib_wrapper.h"

void DxLibWrapper::SystemWatch()
{
	if (ProcessMessage() == -1)
	{
		// DX���C�u�����g�p�I������
		DxLib_End();

		exit(1);
	}

	return;
}
