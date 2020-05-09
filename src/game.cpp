#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : player(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) 
{
  
  pVector.push_back( Person(grid_width, grid_height));

  pVector.push_back( Person(grid_width, grid_height));

  pVector.push_back( Person(grid_width, grid_height));

  pVector.push_back( Person(grid_width, grid_height));

  pVector.push_back( Person(grid_width, grid_height));

  pVector.push_back( Person(grid_width, grid_height));
  
  
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);
  PlaceItem(grid_width,grid_height);

  
  
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
    renderer.Render(player, iVector ,pVector);

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

void Game::PlaceItem(std::size_t grid_width, std::size_t grid_height) {
  Item i(grid_width, grid_height);
  bool freeSpaceFound = false;
  
  while (!freeSpaceFound) { //check if there isnt a colliison with the player or the persons in the map and reset the position until a free space is found
    
    if(i.CheckCollision(player.pos_x,player.pos_y,0))//if there is a collision w player
    {
      i.ResetPosition();
    }
    else 
    {
      bool collisionFound=false;
      for(auto &p : pVector)
      {
        if(i.CheckCollision(p.pos_x,p.pos_y,0)) //if there is a collision
        {
        collisionFound=true;
        i.ResetPosition();
        break;
        }
      }
      if(collisionFound==false)
      {
        freeSpaceFound=true;
      }
    }
   
  }
  //if the free space is found, push it back to the vector os items
  std::cout << "free space found on: x "<<i.pos_x <<" , y " <<i.pos_y <<"\n";
  iVector.push_back(std::move(i));
}

void Game::Update() {
  if (!player.alive) return;

  player.Update();
  int new_x = static_cast<int>(player.pos_x);
  int new_y = static_cast<int>(player.pos_y);
  
  //update position of all persons
  
  for(Person &p : pVector)
  {
    //pVector[0].Update(); 
    p.Update();
    //Check if player came too close to one person
    if(player.CheckCollision(p.pos_x,p.pos_y,1))
    {
      std::cout << "Game Over!!\n";
      player.alive=false;
    } 
  
  }
  
  for(Item &i : iVector)
  { 
    if(!i.consumed)  
    {
      int it=0;
      if(player.CheckCollision(i.pos_x,i.pos_y,0))
      {
        std::cout << "Player got item!!\n";
      //item consumed
      i.consumed=true;
      
      } 
      for(Person &p : pVector)
      {
          if(p.CheckCollision(i.pos_x,i.pos_y,0))
        {
          std::cout << "Person got item!!\n";
        //item consumed
          i.consumed=true;
        } 
      }
    }  
  }
  if(!iVector.empty())
    {
      
   
    for ( std::vector<Item>::iterator it = iVector.begin();it != iVector.end();)
    {
      if(it->consumed){
        iVector.erase(it);
      } 
      else it++;

    }
  }
  // Check if there's food over here
  //if (item.x == new_x && item.y == new_y) {
    //std::cout << "Item found\n";
    //TODO: player found item -> makes game easier 
/*     score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02; */
  //}
}

int Game::GetScore() const { return score; }