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
      if(object_Type!= ObjectType::objectPlayer || ((object_Type== ObjectType::objectPlayer && (pos_y - speed)>=0)))
      {
      pos_y -= speed;
      }
      else std::cout << "Hit screen boundary \n";
      break;

    case Direction::kDown:
      if(object_Type!= ObjectType::objectPlayer || ((object_Type== ObjectType::objectPlayer && (pos_y + speed)<grid_height)))
      {
      pos_y += speed;
      }
      else std::cout << "Hit screen boundary \n";
      break;

    case Direction::kLeft:
      if(object_Type!= ObjectType::objectPlayer || ((object_Type== ObjectType::objectPlayer && (pos_x - speed)>=0)))
      {
      pos_x -= speed;
      }
      else std::cout << "Hit screen boundary \n";
      break;

    case Direction::kRight:
      if(object_Type!= ObjectType::objectPlayer || ((object_Type== ObjectType::objectPlayer && (pos_x + speed)<grid_width)))
      {
      pos_x += speed;
      }
      else std::cout << "Hit screen boundary \n";
      break;
    
    case Direction::kNone:
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