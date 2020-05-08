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
  if(OutsideBoundary()) ResetPosition();
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

bool GameObject::OutsideBoundary()
{
  if(pos_x <-1 || pos_x > grid_width+1 || pos_y < -1 || pos_y > grid_height+1 )
  {
    return true;
  }
  else return false;

}

void GameObject::ResetPosition()
{
  //reset the position of the object to one of the four sides of the screen randomly
  std::random_device dev;
  std::default_random_engine generator(dev());
  std::uniform_int_distribution<int> distribution(1,4);
  int random_side = distribution(generator);
   std::random_device dev2;
   std::default_random_engine generator2(dev2());
  std::uniform_int_distribution<int> distribution_x(0,grid_width);
  int random_x = distribution_x(generator2); 
   std::random_device dev3;
  std::default_random_engine generator3(dev3());
  std::uniform_int_distribution<int> distribution_y(0,grid_height);
  int random_y= distribution_y(generator3);
  switch(random_side)
  { 
    case 1: //1 means coming from left to right
    pos_y=random_y;
    pos_x=-1;
    direction=Direction::kRight;
    break;

    case 2:// 2 means coming from right to left
    pos_y=random_y;
    pos_x=grid_width+1;
    direction=Direction::kLeft;
    break;

    case 3:// 3 means bottom->top
    pos_y=-1;
    pos_x=random_x;
    direction=Direction::kDown;
    break;

    case 4: //4 means top->bottom
    pos_y=grid_height+1;
    pos_x=random_x;
    direction=Direction::kUp;
    break;
  }

}