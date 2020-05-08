
#include "Player.h"
#include <cmath>
#include <iostream>


 Player:: Player(int grid_width, int grid_height) : GameObject(ObjectType::objectPlayer, grid_width,  grid_height, (grid_width/2), (grid_height/2))
 {  
  speed =1.0f;
 }
//Player UpdatePosition function is special so that the player cant leave the frame
 void Player::UpdatePosition() {

  switch (direction) {
    case Direction::kUp:
      if((pos_y - speed)>=0) 
      {
      this->pos_y -= speed;
      }
      direction= Direction::kNone;
      break;

    case Direction::kDown:
      if((pos_y + speed)< getGridHeight())
      {
      this->pos_y += speed;
      }
      direction= Direction::kNone;
      break;

    case Direction::kLeft:
      if((pos_x - speed)>=0)
      {
      this->pos_x -= speed;
      }
      direction= Direction::kNone;
      break;

    case Direction::kRight:
      if((pos_x + speed)<getGridWidth())
      {
      this->pos_x += speed;
      }
      direction= Direction::kNone;
      break;
    
    case Direction::kNone:
      break;
  }
  
}
      