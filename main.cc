#include "dx_lib.h"
#include "window.h"
#include "font.h"
#include "keyboard.h"
#include "selector.h"
#include "character.h"
#include "battle.h"

void MainProcess()
{
	// �\��������
	Window window;

	// �L�����N�^�[�쐬
	Character character1(10, 2);
	Character character2(5, 3);

	// �f���o�g���J�n
	Battle demo_battle;
	demo_battle.Start(character1, character2);

	return;
}
