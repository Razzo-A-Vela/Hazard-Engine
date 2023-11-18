#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

struct Color {
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
  Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) : r(r), g(g), b(b), a(a) {}

  Color setAlpha(Uint8 alpha) {
    return Color(r, g, b, alpha);
  }

  SDL_Color toSDL() {
    return {r, g, b, a};
  }

  Uint32 toSDL(SDL_Surface* windowSurface) {
    return SDL_MapRGBA(windowSurface->format, r, g, b, a);
  }

  void toRenderer(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
  }
};

namespace Colors {
  static const Color BLACK = Color(0, 0, 0);
  static const Color WHITE = Color(255, 255, 255);
  static const Color RED = Color(255, 0, 0);
  static const Color GREEN = Color(0, 255, 0);
  static const Color BLUE = Color(0, 0, 255);
  static const Color YELLOW = Color(255, 255, 0);
  static const Color MAGENTA = Color(255, 0, 255);
  static const Color CYAN = Color(0, 255, 255);
}
