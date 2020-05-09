#include "Item.h"
#include <cmath>
#include <iostream>


 Item::Item(int grid_width, int grid_height) : GameObject(ObjectType::ObjectItem, grid_width,  grid_height, -1, -1)
 {  
  ResetPosition();
  
  speed =0.f;
 }
//The reset Position of an Item places the item in the a random position on the screen (not in the corners as the father) and does not move the item
 void Item::ResetPosition()
 {
//reset the position of the object to one of the four sides of the screen randomly
  
  std::random_device dev;
  std::default_random_engine generator(dev());
  std::uniform_int_distribution<int> distribution_x(0,getGridWidth());
  std::uniform_int_distribution<int> distribution_y(0,getGridHeight());
  this->pos_x= distribution_x(generator);
  this->pos_y= distribution_y(generator);
  std::cout << "Position reset to x:" << pos_x << " and y:" << pos_y <<"\n";
  
 }