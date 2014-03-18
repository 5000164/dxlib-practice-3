#include "../Header/character.h"

Character::Character(int hit_point, int attack_point, int speed) {
  this->hit_point = hit_point;
  this->attack_point = attack_point;
  this->speed = speed;
}

void Character::Init() {
  // 行動可能リスト読み込み
  Json *action_list = new Json("./Data/character__action_list.json");
  action_list->Init();
  this->action_list1 = action_list->GetString("1");
  this->action_list2 = action_list->GetString("2");
  delete action_list;

  return;
}

bool Character::IsFasterThan(Character *target) {
  if (speed > target->speed) {
    return true;
  } else {
    return false;
  }
}

void Character::Action(int action_id, Character *target) {
  // HPがない時は行動できない
  if (hit_point <= 0) {
    return;
  }

  if (action_id = 1) {
    this->Attack(target);
  } else if (action_id = 2) {

  }

  return;
}

void Character::Attack(Character *target) {
  target->hit_point = target->hit_point - this->attack_point;

  return;
}
