#include "../Header/battle.h"

Battle::Battle(Character *c1, Character *c2) {
  this->c1 = c1;
  this->c2 = c2;
}

Battle::~Battle() {
  WaitTimer(1000);
}

void Battle::Init() {
  // メッセージ読み込み
  Json *message = new Json("./Data/battle__message.json");
  message->Init();
  this->message1 = message->GetString("1");
  this->message2 = message->GetString("2");
  this->message3 = message->GetString("3");
  this->message4 = message->GetString("4");
  delete message;

  return;
}

void Battle::Run() {
  System *system = new System();
  int action_id = 1;
  int action_result = 0;
  bool continuation_flag = true;

  while (continuation_flag) {
    system->Watch();
    action_id = this->SelectPhase(action_id);
    action_result = this->ActionPhase(action_id);

    switch (action_result) {
      case 0: {
        continuation_flag = true;
        break;
      }
      case 1: {
        continuation_flag = false;
        break;
      }
      case 2: {
        continuation_flag = false;
        break;
      }
      case 3: {
        continuation_flag = false;
        break;
      }
    }
  }

  delete system;

  return;
}

int Battle::SelectPhase(int action_id) {
  System *system = new System();
  Keyboard *keyboard = new Keyboard();
  Rendering *rendering = new Rendering();
  rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
  rendering->BattleMessage(action_id, message3, std::to_string(c1->hit_point), message4, std::to_string(c2->hit_point));
  bool continuation_flag = true;

  while (continuation_flag) {
    system->Watch();

    // キーボードの入力待ち
    keyboard->InputOnce();

    if (keyboard->IsPressReturn()) {
      continuation_flag = false;
    } else if (keyboard->IsPressUp()) {
      action_id = 1;

      // メニュー表示
      rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
    } else if (keyboard->IsPressDown()) {
      action_id = 2;

      // メニュー表示
      rendering->BattleMenu(action_id, c1->action_list1, c1->action_list2);
    }
  }

  delete rendering;
  delete keyboard;
  delete system;

  return action_id;
}

int Battle::ActionPhase(int action_id) {
  Rendering *rendering = new Rendering();
  int action_result = 0;

  switch (action_id) {
    case 1: {
      // 素早さの早いキャラクターから行動
      if (c1->IsFasterThan(c2))
      {
        c1->Action(action_id, c2);
        c2->Action(1, c1);
      }
      else
      {
        c2->Action(1, c1);
        c1->Action(action_id, c2);
      }

      rendering->BattleMessage(action_id, message3, std::to_string(c1->hit_point), message4, std::to_string(c2->hit_point));

      if (c1->hit_point <= 0) {
        action_result = 1;
      }
      if (c2->hit_point <= 0) {
        action_result = 2;
      }

      break;
    }
    case 2: {
      action_result = 3;
      break;
    }
  }

  delete rendering;

  return action_result;
}
