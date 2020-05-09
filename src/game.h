#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "Player.h"
#include "Person.h"
#include "Item.h"


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  

 private:
  Player player;
  std::vector<Person> pVector;
  std::vector<Item> iVector;
  int respawnTime=10;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  long long timestamp_begin= SDL_GetTicks();;
  Uint32 elapsed_time;
  int difficulty=5;
  int score{0};

  void PlaceItem(std::size_t grid_width, std::size_t grid_height);
  void Update();
};

#endif