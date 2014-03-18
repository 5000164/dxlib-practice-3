#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/character.h"
#include "../Header/battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // �\��������
  window:: Window *window = new window::Window();
  window->Init();

  // �L�����N�^�[�쐬
  character::Character *character1 = new character::Character(10, 3, 10);
  character1->Init();
  character::Character *character2 = new character::Character(8, 4, 8);
  character2->Init();

  // �f���o�g���J�n
  battle::Battle *demo_battle = new battle::Battle(character1, character2);
  demo_battle->Init();
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;

  // �\���I��
  delete window;

  return 0;
}
