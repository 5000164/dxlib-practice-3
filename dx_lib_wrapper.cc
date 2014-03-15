#include "dx_lib_wrapper.h"

DxLibWrapper::DxLibWrapper()
{
	// �E�B���h�E�Ŏ��s
	ChangeWindowMode(TRUE);

	// 1024x768px�A32bit�Ŏ��s
	SetGraphMode(1024, 768, 32);

	// �ُ폈���ŋ����I��
	if (DxLib_Init() == -1)
	{
		// DX���C�u�����g�p�I������
		DxLib_End();

		exit(1);
	}
}

DxLibWrapper::~DxLibWrapper()
{
	// DX���C�u�����g�p�I������
	DxLib_End();
}

void DxLibWrapper::SystemWatch()
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
