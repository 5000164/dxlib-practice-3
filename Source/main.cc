#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/character.h"
#include "../Header/battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  // �\��������
  Window *window = new Window();
  window->Init();

  // �L�����N�^�[�쐬
  Character *character1 = new Character(10, 2, 5);
  character1->Init();
  Character *character2 = new Character(5, 3, 8);
  character2->Init();

  // �f���o�g���J�n
  Battle *demo_battle = new Battle(character1, character2);
  demo_battle->Init();
  demo_battle->Run();
  delete demo_battle;

  delete character2;
  delete character1;

  // �\���I��
  delete window;

  return 0;
}
