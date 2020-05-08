#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "GameObject.h"

class Player:public GameObject {
 public:

  Player(int grid_width, int grid_height);

  bool alive{true};

 private:
  void UpdatePosition() override;
};

#endif