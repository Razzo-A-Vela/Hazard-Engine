#pragma once
#include <iostream>
#include <string>
#include <chrono>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

#include "types\Vector2.hpp"
#include "types\Window.hpp"
#include "Painthandler.hpp"
#include "FontHandler.hpp"
#include "Input.hpp"


typedef void (*update_func)(double deltaTime);
typedef void (*draw_func)(PaintHandler* handler);
typedef void (*quit_func)(void);

class Hazard {
public:
  static void init();
  static void createWindow(std::string title, Vector2Int size);
  static void quit();
  static void run();
  static void onUpdate(update_func update) { updateFunc = update; }
  static void onDraw(draw_func draw) { drawFunc = draw; }
  static void onQuit(quit_func quit) { quitFunc = quit; }
  static int getFPS() { return fps; }
  static Vector2Int getWindowSize() { return window->size; }

private:
  static inline int fps = 0;
  static inline double deltaTime = 0;
  static inline bool initialized = false;

  static inline Window* window = NULL;
  static inline update_func updateFunc = NULL;
  static inline draw_func drawFunc = NULL;
  static inline quit_func quitFunc = NULL;
};
