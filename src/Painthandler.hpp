#pragma once
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

#include "types\Vector2.hpp"
#include "types\Window.hpp"
#include "types\Color.hpp"
#include "FontHandler.hpp"

class PaintHandler {
public:
  PaintHandler(Window* window) : window(window) {}
  void drawRect(Vector2Int pos, Vector2Int size, bool fill);
  Vector2Int drawText(Vector2Int pos, std::string text);
  void fillBackground(Color color);

  void setColor(Color color) { currentColor = color; }
  void setFont(std::string font) { currentFont = font; }

  static inline const std::string DEFAULT_FONT = "";

private:
  Window* window;
  Color currentColor = Colors::WHITE;
  std::string currentFont = DEFAULT_FONT;
};
