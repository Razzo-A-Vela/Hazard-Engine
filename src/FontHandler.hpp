#pragma once
#include <string>
#include <unordered_map>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

class FontHandler {
public:
  static TTF_Font* getFont(std::string name) {
    return loadedFonts.at(name);
  }

  static void addFont(std::string name, std::string path, int size) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), size);
    loadedFonts.insert({ name, font });
  }

  static void setDefaultFont(std::string name) {
    defaultFont = name;
  }

  static TTF_Font* getDefaultFont() {
    return getFont(defaultFont);
  }

  static void close() {
    for (auto font = loadedFonts.begin(); font != loadedFonts.end(); font++) {
      TTF_CloseFont(font->second);
    }
    loadedFonts.clear();
  }

private:
  static inline std::unordered_map<std::string, TTF_Font*> loadedFonts;
  static inline std::string defaultFont = "";
};
