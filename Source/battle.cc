#include "../Header/battle.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/system.h"
#include "../Header/json.h"
#include "../Header/keyboard.h"
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
    this->SelectPhase();
    this->ActionPhase();

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

void Battle::SelectPhase() {
  dx_system::System *system = new dx_system::System();
  keyboard::Keyboard *keyboard = new keyboard::Keyboard();
  rendering::Rendering *rendering = new rendering::Rendering();
  bool continuation_flag = true;

  rendering->Battle(this);

  while (continuation_flag) {
    system->Watch();

    keyboard->WaitInputOnce();

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

  return;
}

void Battle::ActionPhase() {
  rendering::Rendering *rendering = new rendering::Rendering();

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

  rendering->Battle(this);

  delete rendering;

  return;
}

}
