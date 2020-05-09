#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::ChangeDirection(Player &player, Player::Direction input) const 
{
  player.direction = input;
  
}

void Controller::HandleInput(bool &running, Player &player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          //std::cout << "UP captured \n";
          ChangeDirection(player, Player::Direction::kUp);
          break;

        case SDLK_DOWN:
          //std::cout << "down captured \n";
          ChangeDirection(player, Player::Direction::kDown);
          break;

        case SDLK_LEFT:
          //std::cout << "left captured \n";
          ChangeDirection(player, Player::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          //std::cout << "right captured \n";
          ChangeDirection(player, Player::Direction::kRight);
          break;
      }
    }
  }
}