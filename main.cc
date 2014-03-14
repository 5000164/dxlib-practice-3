#include "dx_lib.h"
#include "window.h"
#include "font.h"
#include "keyboard.h"
#include "selector.h"
#include "battle.h"



// ���C������
void MainProcess()
{
	// �\��������
	Window window;
	Font font;
	Keyboard key;
	Selector selector;



	// �f���o�g���J�n
	Battle demo_battle(font, selector);
	demo_battle.Start();



	///
	/// ���[�v����
	///

	// �I�����Ă��郁�j���[
	int command_selector = 0;

	// Esc�L�[�̓��͂Ń��[�v�I��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �L�[�{�[�h�̓��͑҂�
		key.OnceInput();

		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			demo_battle.Command(command_selector);
		}
		else if (CheckHitKey(KEY_INPUT_UP))
		{
			command_selector = 0;
			demo_battle.Menu(command_selector);
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			command_selector = 1;
			demo_battle.Menu(command_selector);
		}
	}
	demo_battle.End();



	///
	/// �I������
	///

	return;
}
