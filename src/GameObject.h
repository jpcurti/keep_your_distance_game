#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "SDL.h"

enum ObjectType
{
  noObject,
  objectPlayer,
  objectPerson,
  Objecttem,

};

class GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  GameObject(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        pos_x(grid_width / 2),
        pos_y(grid_height / 2),
        object_Type(ObjectType::noObject) {}

  GameObject(ObjectType objectType, int grid_width, int grid_height, int posx, int posy)
      : grid_width(grid_width),
        grid_height(grid_height),
        pos_x(posx),
        pos_y(posy),
        object_Type(objectType) {}
  ObjectType getType() { return object_Type; }
  bool CheckCollision(int x, int y);
  Direction direction = Direction::kUp;
  void Update();
  float speed{0.1f};
  float pos_x;
  float pos_y;
 

 private:
  void ConsumeItem();
  void UpdatePosition();
  ObjectType object_Type;
  int grid_width;
  int grid_height;
};

#endif