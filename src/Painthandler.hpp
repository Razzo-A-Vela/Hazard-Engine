#pragma once
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

#include "Vector2.hpp"
#include "Window.hpp"
#include "Color.hpp"
#include "FontHandler.hpp"

class PaintHandler {
public:
  PaintHandler(Window* window) : window(window) {}
  void drawRect(Vector2Int pos, Vector2Int size, bool fill);
  void fillBackground(Color color);
  void setColor(Color color) { currentColor = color; }
  Vector2Int drawText(Vector2Int pos, std::string text);
  void setFont(std::string font) { currentFont = font; }

  static inline const std::string DEFAULT_FONT = "";

private:
  Window* window;
  Color currentColor = Colors::WHITE;
  std::string currentFont = DEFAULT_FONT;
};
