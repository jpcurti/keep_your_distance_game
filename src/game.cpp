#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : player(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceItem();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, player);
    Update();
    renderer.Render(player, item);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceItem() {
  int x, y;
  bool freeSpaceFound = false;
  while (!freeSpaceFound) {
    x = random_w(engine);
    y = random_h(engine);
    // TO:DO Check that the location is not occupied by any of the game objects
     if (!player.CheckCollision(x, y)) {
      item.x = x;
      item.y = y;
      freeSpaceFound=true;
    } 
    //TODO: Check also for all other Person objects
    /*
    for (auto x: vector of persons)
    {
      if (!x.CheckCollision(x, y)) {
      item.x = x;
      item.y = y;
      
      freeSpaceFound=true;
    }
    */
  }
}

void Game::Update() {
  if (!player.alive) return;

  player.Update();

  int new_x = static_cast<int>(player.pos_x);
  int new_y = static_cast<int>(player.pos_y);

  // Check if there's item over here
  if (item.x == new_x && item.y == new_y) {
    //TODO: player found item -> makes game easier 
/*     score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02; */
  }
}

int Game::GetScore() const { return score; }