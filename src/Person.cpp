#include "Person.h"
#include <cmath>
#include <iostream>


 Person:: Person(int grid_width, int grid_height) : GameObject(ObjectType::objectPerson, grid_width,  grid_height, -1, -1)
 {  
  ResetPosition();
  
  speed =0.1f;
 }