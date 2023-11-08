#include "Painthandler.hpp"

void PaintHandler::drawRect(Vector2Int pos, Vector2Int size, bool fill) {
  SDL_Rect rect = SDL_Rect{pos.x, pos.y, size.x, size.y};
  currentColor.toRenderer(window->renderer);
  if (fill)
    SDL_RenderFillRect(window->renderer, &rect);
  else
    SDL_RenderDrawRect(window->renderer, &rect);
}

void PaintHandler::fillBackground(Color color) {
  color.setAlpha(255).toRenderer(window->renderer);
  SDL_RenderClear(window->renderer);
}

//TODO: add drawing of text
Vector2Int PaintHandler::drawText(Vector2Int pos, std::string text) {
  TTF_Font* font = currentFont == DEFAULT_FONT ? FontHandler::getDefaultFont() : FontHandler::getFont(currentFont);
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), currentColor.toSDL());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, surface);
  SDL_Rect rect;
  rect.x = pos.x;
  rect.y = pos.y;
  rect.w = surface->w;
  rect.h = surface->h;

  SDL_RenderCopy(window->renderer, texture, NULL, &rect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
  return { rect.w, rect.h };
}
