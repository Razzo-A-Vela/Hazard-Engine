#include "Input.hpp"

void Input::init() {
  for (char c = 'a'; c <= 'z'; c++) keysPressed.insert({ Keys::toKeyCode(c), false });
  for (char c = '0'; c <= '9'; c++) keysPressed.insert({ Keys::toKeyCode(c), false });
  keysPressed.insert({ Keys::toKeyCode(','), false });
  keysPressed.insert({ Keys::toKeyCode('.'), false });
  keysPressed.insert({ Keys::toKeyCode('-'), false });
  keysPressed.insert({ Keys::toKeyCode('+'), false });
  keysPressed.insert({ Keys::toKeyCode('\''), false });
  keysPressed.insert({ Keys::toKeyCode('\\'), false });
  keysPressed.insert({ Keys::toKeyCode('<'), false });
  
  keysPressed.insert({ Keys::Space, false });
  keysPressed.insert({ Keys::LCtrl, false });
  keysPressed.insert({ Keys::LShift, false });
  keysPressed.insert({ Keys::LAlt, false });
  keysPressed.insert({ Keys::Escape, false });
  keysPressed.insert({ Keys::RCtrl, false });
  keysPressed.insert({ Keys::RShift, false });
  keysPressed.insert({ Keys::RAlt, false });
  keysPressed.insert({ Keys::Backspace, false });
  keysPressed.insert({ Keys::Enter, false });
  keysPressed.insert({ Keys::Tab, false });
}

void Input::update(SDL_Event* event) {
  if (event->type == SDL_KEYDOWN) {
    KeyCode key = event->key.keysym.sym;

    if (keysPressed.count(key) == 0) return;
    if (!keysPressed.at(key)) keysDown.emplace(key);
    keysDownRepeating.emplace(key);
    keysPressed.at(key) = true;

  } else if (event->type == SDL_KEYUP) {
    KeyCode key = event->key.keysym.sym;

    if (keysPressed.count(key) == 0) return;
    keysUp.emplace(key);
    keysPressed.at(key) = false;

  } else if (event->type == SDL_MOUSEMOTION) {
    mousePos = Vector2Int(event->motion.x, event->motion.y);

  } else if (event->type == SDL_MOUSEBUTTONDOWN) {
    mousePos = Vector2Int(event->button.x, event->button.y);

    mouseButtonsPressed[event->button.button - 1] = true;
    mouseButtonsDown[event->button.button - 1] = true;

  } else if (event->type == SDL_MOUSEBUTTONUP) {
    mousePos = Vector2Int(event->button.x, event->button.y);

    mouseButtonsPressed[event->button.button - 1] = false;
    mouseButtonsUp[event->button.button - 1] = true;

  }
}

void Input::reset() {
  keysDownRepeating.clear();
  keysDown.clear();
  keysUp.clear();
  
  for (int i = 0; i < 3; i++) {
    mouseButtonsDown[i] = false;
    mouseButtonsUp[i] = false;
  }
}

std::unordered_set<KeyCode> Input::getPressedKeys() {
  std::unordered_set<KeyCode> ret;
  
  for (auto key : keysPressed) 
    if (key.second) ret.emplace(key.first);
  
  return ret;
}

void Input::inputString(std::stringstream* stream) {
  char c = 0;
  for (KeyCode key : keysDownRepeating) {
    if (key == Keys::Backspace) {
      std::string str = stream->str();
      if (str.size() == 0) return;
      
      stream->str(str.erase(str.size() - 1));
      stream->seekp(0, std::ios_base::end);
      return;

    } else if (key == Keys::Space)
      (*stream) << ' ';

    else if (!Keys::isMod(key) && key >= 33 && key <= 126) {
      c = key;
      break;
    }
  }

  if (keyPressed(Keys::LShift) || keyPressed(Keys::RShift)) c = std::toupper(c);
  if (c != 0) (*stream) << c;
}
