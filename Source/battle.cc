#include "../Header/battle.h"

Battle::Battle(Character *c1, Character *c2)
{
  this->c1 = c1;
  this->c2 = c2;
}

Battle::~Battle()
{
  WaitTimer(1000);
}

void Battle::Init()
{
  // ���b�Z�[�W�ǂݍ���
  Json *message = new Json("./Data/battle__message.json");
  message->Init();
  this->message1 = message->GetString("1");
  this->message2 = message->GetString("2");
  this->message3 = message->GetString("3");
  this->message4 = message->GetString("4");
  delete message;

  return;
}

void Battle::Run()
{
  System *system = new System();
  Keyboard *keyboard = new Keyboard();
  Rendering *rendering = new Rendering();
  int action_id = 1;
  bool continuation_flag = true;

  while (continuation_flag)
  {
    rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
    rendering->BattleMessage(action_id, message3, std::to_string(c1->hit_point), message4, std::to_string(c2->hit_point));

    // �L�[�{�[�h�̓��͑҂�
    keyboard->InputOnce();

    if (keyboard->IsPressReturn())
    {
      // �f�����̑����L�����N�^�[����s��
      if (c1->IsFasterThan(c2))
      {
        c1->Action(action_id, c2);
        c2->Action(1, c1);
      }
      else
      {
        c1->Action(action_id, c2);
        c2->Action(1, c1);
      }

      rendering->BattleMessage(action_id, message3, std::to_string(c1->hit_point), message4, std::to_string(c2->hit_point));

      if (c1->hit_point <= 0 || c2->hit_point <= 0) {
        continuation_flag = false;
      }
    }
    else if (keyboard->IsPressUp())
    {
      action_id = 1;

      // ���j���[�\��
      rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
    }
    else if (keyboard->IsPressDown())
    {
      action_id = 2;

      // ���j���[�\��
      rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
    }

    system->Watch();
  }

  delete rendering;
  delete keyboard;
  delete system;

  return;
}
