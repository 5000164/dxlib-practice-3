#include "DxLib.h"
#include "forward_declaration.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�Ŏ��s
	ChangeWindowMode(TRUE);

	// 1024x768px�A32bit�Ŏ��s
	SetGraphMode(1024, 768, 32);

	// �ُ폈���ŋ����I��
	if (DxLib_Init() == -1)	return -1;

	// ���C�������Ăяo��
	MainProcess();

	// DX���C�u�����g�p�I������
	DxLib_End();

	return 0;
}
