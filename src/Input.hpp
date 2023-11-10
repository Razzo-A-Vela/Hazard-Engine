#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "types\Vector2.hpp"


typedef SDL_Keycode KeyCode;

namespace Keys {
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

  inline static KeyCode toKeyCode(char c) {
    return (KeyCode) c;
  }

  inline static std::string toString(KeyCode key) {
    return std::regex_replace(std::string(SDL_GetKeyName(key)), std::regex("Return"), "Enter");
  }

  inline bool isMod(KeyCode key) {
    switch (key) {
      case Keys::LShift:
      case Keys::LCtrl:
      case Keys::LAlt:
      case Keys::RShift:
      case Keys::RCtrl:
      case Keys::RAlt:
        return true;

      default:
        return false;
    }
  }
}

enum class Axis {
  horizontal,
  vertical,
  mouseX,
  mouseY
};

class Input {
public:
  static void init();
  static void update(SDL_Event* event);
  static void reset();

  static bool keyPressed(KeyCode key) { return keysPressed.at(key); }
  static bool keyDownRepeating(KeyCode key) { return keysDownRepeating.count(key) != 0; }
  static bool keyDown(KeyCode key) { return keysDown.count(key) != 0; }
  static bool keyUp(KeyCode key) { return keysUp.count(key) != 0; }
  static std::unordered_set<KeyCode> getPressedKeys();
  static void inputString(std::stringstream* stream);

  static Vector2Int getMousePos() { return mousePos.copy(); }
  static bool mousePressed(int mouseButton) { return mouseButtonsPressed[mouseButton - 1]; }
  static bool mouseDown(int mouseButton) { return mouseButtonsDown[mouseButton - 1]; }
  static bool mouseUp(int mouseButton) { return mouseButtonsUp[mouseButton - 1]; }
  static float getAxis(Axis axis);

private:
  static inline std::unordered_map<KeyCode, bool> keysPressed;
  static inline std::unordered_set<KeyCode> keysDownRepeating;
  static inline std::unordered_set<KeyCode> keysDown;
  static inline std::unordered_set<KeyCode> keysUp;

  static inline Vector2Int mousePos;
  static inline Vector2 mouseRel;
  static inline bool mouseButtonsPressed[3] = { false };
  static inline bool mouseButtonsDown[3] = { false };
  static inline bool mouseButtonsUp[3] = { false };
};
