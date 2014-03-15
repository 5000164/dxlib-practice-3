#include "dx_lib_wrapper.h"
#include "window.h"
#include "character.h"
#include "battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �\��������
	DxLibWrapper dxlib;
	Window window;

	// �L�����N�^�[�쐬
	Character character1(10, 2);
	Character character2(5, 3);

	// �f���o�g���J�n
	Battle demo_battle;
	demo_battle.Start(dxlib, character1, character2);

	return 0;
}
