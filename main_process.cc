#include <fstream>
#include "dx_lib.h"
#include "forward_declaration.h"
#include "objects.h"
#include "picojson.h"



// ���C������
void MainProcess()
{
	Json json;

	picojson::array array = json.GetArray("text.json", "menu");

	std::string menu_text[2];
	int count = 0;
	for (picojson::array::iterator i = array.begin(); i != array.end(); i++) {
		menu_text[count] = i->get<std::string>();
		count++;
	}






	Window window;
	Font font;
	Triangle selector;



	// �e�L�X�g�\���J�n�ʒu
	int menu_text_position[2] = { 60, 20 };

	ClearDrawScreen();
	int position_1[2] = { 35, 20 };
	int position_2[2] = { 35, 40 };
	int position_3[2] = { 45, 30 };
	int color[3] = { 230, 230, 230 };
	selector.Draw(position_1, position_2, position_3, color);
	ScreenFlip();



	///
	/// ���[�v����
	///

	// �I�����Ă��郁�j���[
	int menu_selector = 0;

	// Esc�L�[�̓��͂Ń��[�v�I��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �L�[�{�[�h�̓��͑҂�
		OnceKeyInput();


		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			run(menu_selector);
		}
		else if (CheckHitKey(KEY_INPUT_UP))
		{
			// �����L�[��F��Ɉړ�
			menu_selector = 0;

			int position_1[2] = { 35, 20 };
			int position_2[2] = { 35, 40 };
			int position_3[2] = { 45, 30 };
			int color[3] = { 230, 230, 230 };
			selector.Draw(position_1, position_2, position_3, color);
			ScreenFlip();
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// �����L�[���F���Ɉړ�
			menu_selector = 1;

			int position_1[2] = { 35, 51 };
			int position_2[2] = { 35, 71 };
			int position_3[2] = { 45, 61 };
			int color[3] = { 230, 230, 230 };
			selector.Draw(position_1, position_2, position_3, color);
			ScreenFlip();
		}
	}



	///
	/// �I������
	///

	return;
}




///
/// �L�[�̘A�����͂�h�~����
///
void OnceKeyInput()
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



///
/// ���s
///
void run(int menu_selector)
{
	Font font;
	if (menu_selector == 0)
	{
		ClearDrawScreen();
		char text[256][256] = { "����������" };
		int position[2] = { 50, 50 };
		font.Draw(text, 1, position);
		ScreenFlip();
	}
	else if (menu_selector == 1)
	{
		ClearDrawScreen();
		char text[256][256] = { "������" };
		int position[2] = {50, 50};
		font.Draw(text, 2, position);
		ScreenFlip();
	}
}
