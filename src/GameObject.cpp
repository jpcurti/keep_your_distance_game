#include "GameObject.h"
#include <cmath>
#include <iostream>

void GameObject::Update() {
  /* SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating. */
  UpdatePosition();
  /* SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating. */

 
}

void GameObject::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      pos_y -= speed;
      break;

    case Direction::kDown:
      pos_y += speed;
      break;

    case Direction::kLeft:
      pos_x -= speed;
      break;

    case Direction::kRight:
      pos_x += speed;
      break;
  }
}


void GameObject::ConsumeItem() { 
  //if object is player, reduce speed multiplier and consume item
  if(this->getType() == ObjectType::objectPlayer)
  {
    //todo: reduce game speed multiplier and consume item
  }
  //else if object is npc, just consume item
  else if(this->getType() == ObjectType::objectPerson)
  {
    //todo:  consume item
  }

  //else nothing happens

 }

// TODO: check if cell is occupied by GameObject.
bool GameObject::CheckCollision(int x, int y) {
   if (x == static_cast<int>(pos_x) && y == static_cast<int>(pos_y)) {
    return true;
  }

  return false;
}