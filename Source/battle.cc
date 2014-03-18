#include "../Header/battle.h"
#include "../Header/rendering.h"

namespace battle {

Battle::Battle(character::Character *c1, character::Character *c2) {
  this->c1 = c1;
  this->c2 = c2;
  this->action_id = 1;
  this->action_result = 0;
  this->continuation_flag = true;
}

Battle::~Battle() {
  WaitTimer(1000);
}

void Battle::Init() {
  // メッセージ読み込み
  json::Json *message = new json::Json("./Data/battle__message.json");
  message->Init();
  this->message1 = message->GetString("1");
  this->message2 = message->GetString("2");
  this->message3 = message->GetString("3");
  this->message4 = message->GetString("4");
  delete message;

  return;
}

void Battle::Run() {
  dx_system::System *system = new dx_system::System();

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
  dx_system::System *system = new dx_system::System();
  keyboard::Keyboard *keyboard = new keyboard::Keyboard();
  rendering::Rendering *rendering = new rendering::Rendering();
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
    } else if (keyboard->IsPressDown()) {
      action_id = 2;
    }

    rendering->Battle(this);
  }

  delete rendering;
  delete keyboard;
  delete system;

  return action_id;
}

int Battle::ActionPhase(int action_id) {
  rendering::Rendering *rendering = new rendering::Rendering();
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

}
