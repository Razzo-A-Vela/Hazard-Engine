#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Vector2.hpp"


struct Window {
  const Vector2Int size;

  SDL_Window* window;
  SDL_Renderer* renderer;
};
