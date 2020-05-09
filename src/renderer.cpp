#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Keep your distance!", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }


  sdl_surface = SDL_LoadBMP("../img/background.bmp");
  if (sdl_surface == NULL)
  {
    std::cerr << "surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
     
  
  }
   sdl_player_surface = SDL_LoadBMP("../img/player.bmp");
  if (sdl_player_surface == NULL)
  {
    std::cerr << "surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
     
  
  }
   sdl_virus_surface = SDL_LoadBMP("../img/corona.bmp");
  if (sdl_virus_surface == NULL)
  {
    std::cerr << "surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
     
  
  }
  sdl_mask_surface = SDL_LoadBMP("../img/mask.bmp");
  if (sdl_mask_surface == NULL)
  {
    std::cerr << "surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
     
  
  }
  sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_surface);
  if (!sdl_texture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
      
  }

  sdl_player_texture= SDL_CreateTextureFromSurface(sdl_renderer, sdl_player_surface);
  if (!sdl_player_texture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
      
  }
   sdl_virus_texture= SDL_CreateTextureFromSurface(sdl_renderer, sdl_virus_surface);
  if (!sdl_virus_texture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
      
  }
   sdl_mask_texture= SDL_CreateTextureFromSurface(sdl_renderer, sdl_mask_surface);
  if (!sdl_mask_texture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
      
  }

  SDL_FreeSurface(sdl_surface);
	// Update window
	SDL_UpdateWindowSurface( sdl_window );
  
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Player const player, std::vector<Item>  const &iVector, std::vector<Person> const &pVector) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;


   // Clear screen
  //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
 
  SDL_RenderClear(sdl_renderer); 
  SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
  //SDL_RenderPresent(sdl_renderer);
  

  // Render all items
  for(Item i : iVector)
  {
  //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = i.pos_x * block.w;
  block.y = i.pos_y * block.h;
  //SDL_RenderFillRect(sdl_renderer, &block);

    SDL_RenderCopy(sdl_renderer, sdl_mask_texture, NULL, &block);
  }
  // Render other persons
  for(Person p : pVector)
  {
    //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    block.x = static_cast<int>(p.pos_x) * block.w;
    block.y = static_cast<int>(p.pos_y) * block.h;
    //SDL_RenderFillRect(sdl_renderer, &block);
    SDL_RenderCopy(sdl_renderer, sdl_virus_texture, NULL, &block);
  }

  // Render Player 
  block.x = static_cast<int>(player.pos_x) * block.w;
  block.y = static_cast<int>(player.pos_y) * block.h;
  /* if (player.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block); */

   
  SDL_RenderCopy(sdl_renderer, sdl_player_texture, NULL, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Game Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
