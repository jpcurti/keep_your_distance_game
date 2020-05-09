#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <random>
#include "SDL.h"

enum ObjectType
{
  noObject,
  objectPlayer,
  objectPerson,
  ObjectItem,

};

class GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight, kNone };

  GameObject(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        pos_x(grid_width / 2),
        pos_y(grid_height / 2),
        object_Type(ObjectType::noObject) {}

  GameObject(ObjectType objectType, int grid_width, int grid_height, int posx, int posy)
      : object_Type(objectType),
        grid_width(grid_width),
        grid_height(grid_height),
        pos_x(posx),
        pos_y(posy){}
  ObjectType getType()const  { return object_Type; }
  int getGridWidth() const {return grid_width;}
  int getGridHeight() const {return grid_height;}
  bool CheckCollision(int x, int y, int radius);
  Direction direction = Direction::kNone;
  void Update();
  float speed{0.1f};
  float pos_x;
  float pos_y;
  virtual void ResetPosition();
  bool OutsideBoundary();
 

 private:
  void ConsumeItem();
  virtual void UpdatePosition();
  ObjectType object_Type;
  int grid_width;
  int grid_height;
  
  
};

#endif