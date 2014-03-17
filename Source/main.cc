#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/character.h"
#include "../Header/battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
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

  // �\��������
  Window *window = new Window();

  // �L�����N�^�[�쐬
  Character *character1 = new Character(10, 2);
  Character *character2 = new Character(5, 3);

  // �f���o�g���J�n
  Battle *demo_battle = new Battle(character1, character2);
  demo_battle->Init();
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;
  delete window;

  // DX���C�u�����g�p�I������
  DxLib_End();

  return 0;
}
