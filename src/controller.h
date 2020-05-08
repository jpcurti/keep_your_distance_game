#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Player.h"

class Controller {
 public:
  void HandleInput(bool &running, Player &player) const;

 private:
  void ChangeDirection(Player &player, Player::Direction input) const;
};

#endif