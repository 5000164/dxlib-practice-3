#include <fstream>
#include "dx_lib.h"
#include "forward_declaration.h"
#include "objects.h"
#include "picojson.h"



// ���C������
void MainProcess()
{
	Json json;

	// ���j���[���͓ǂݍ���
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


	// ��ʕ`��
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	font.Draw(menu_text[0], 50, 50);
	font.Draw(menu_text[1], 50, 100);
	selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
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

			SetDrawScreen(DX_SCREEN_BACK);
			ClearDrawScreen();
			font.Draw(menu_text[0], 50, 50);
			font.Draw(menu_text[1], 50, 100);
			selector.Draw(35, 49, 35, 69, 45, 59, 230, 230, 230);
			ScreenFlip();
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			// �����L�[���F���Ɉړ�
			menu_selector = 1;

			SetDrawScreen(DX_SCREEN_BACK);
			ClearDrawScreen();
			font.Draw(menu_text[0], 50, 50);
			font.Draw(menu_text[1], 50, 100);
			selector.Draw(35, 99, 35, 119, 45, 109, 230, 230, 230);
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
	Json json;

	if (menu_selector == 0)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = json.GetString("text.json", "battle");
		font.Draw(string, 100, 150);
	}
	else if (menu_selector == 1)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		std::string string = json.GetString("text.json", "escape");
		font.Draw(string, 100, 150);
	}
}
