#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Player.h"
#include "Person.h"
#include "Item.h"
#include <iostream>


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Player const player, std::vector<Item>  const &iVector, std::vector<Person> const &pVector); 
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_surface;
  SDL_Surface *sdl_player_surface;
  SDL_Surface *sdl_player2_surface;
  SDL_Surface *sdl_virus_surface;
  SDL_Surface *sdl_virus2_surface;
  SDL_Surface *sdl_mask_surface;
  SDL_Texture *sdl_texture;
  SDL_Texture *sdl_player_texture;
  SDL_Texture *sdl_player2_texture;
  SDL_Texture *sdl_virus_texture;
  SDL_Texture *sdl_virus2_texture;
  SDL_Texture *sdl_mask_texture;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif