#include "Player.h"
#include <cmath>
#include <iostream>


 Player:: Player(int grid_width, int grid_height) : GameObject(ObjectType::objectPlayer, grid_width,  grid_height, (grid_width/2), (grid_height/2))
 {  
  speed =1.0f;
 }
      