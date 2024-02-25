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
  PaintHandler(Window* window) : window(window) { currentColor.toRenderer(window->renderer); }
  void drawRect(Vector2Int pos, Vector2Int size, bool fill = true);
  Vector2Int drawText(Vector2Int pos, std::string text);
  void drawLine(Vector2Int pos1, Vector2Int pos2);
  void fillBackground(Color color);

  void setColor(Color color) { currentColor = color; currentColor.toRenderer(window->renderer); }
  void setFont(std::string font) { currentFont = font; }

  static inline const std::string DEFAULT_FONT = "";

private:
  Window* window;
  Color currentColor = Colors::WHITE;
  std::string currentFont = DEFAULT_FONT;
};
