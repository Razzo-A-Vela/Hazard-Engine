#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#define SDL_MAIN_HANDLED
#include <SDL.h>


typedef SDL_Keycode KeyCode;

namespace Keys {
  static KeyCode toKeyCode(char c) {
    return (KeyCode) c;
  }

  static std::string toString(KeyCode key) {
    return std::regex_replace(std::string(SDL_GetKeyName(key)), std::regex("Return"), "Enter");
  }

  static const KeyCode Space = SDLK_SPACE;
  static const KeyCode LCtrl = SDLK_LCTRL;
  static const KeyCode LShift = SDLK_LSHIFT;
  static const KeyCode LAlt = SDLK_LALT;
  static const KeyCode Escape = SDLK_ESCAPE;
  static const KeyCode RCtrl = SDLK_RCTRL;
  static const KeyCode RShift = SDLK_RSHIFT;
  static const KeyCode RAlt = SDLK_RALT;
  static const KeyCode Backspace = SDLK_BACKSPACE;
  static const KeyCode Enter = SDLK_RETURN;
  static const KeyCode Tab = SDLK_TAB;
}

class Input {
public:
  static void init();
  static void update(SDL_Event* event);
  static void reset();

  static bool isPressed(KeyCode key) { return keysPressed.at(key); }
  static bool keyDown(KeyCode key) { return keysDown.count(key) != 0; }
  static bool keyUp(KeyCode key) { return keysUp.count(key) != 0; }
  static std::unordered_set<KeyCode> getPressedKeys();
  static void inputString(std::stringstream* stream);
  static bool isMod(KeyCode key);

private:
  static inline std::unordered_map<KeyCode, bool> keysPressed;
  static inline std::unordered_set<KeyCode> keysDown;
  static inline std::unordered_set<KeyCode> keysUp;
};
