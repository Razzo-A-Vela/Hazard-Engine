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
    keysPressed.at(key) = true;
  } else if (event->type == SDL_KEYUP) {
    KeyCode key = event->key.keysym.sym;

    if (keysPressed.count(key) == 0) return;
    keysUp.emplace(key);
    keysPressed.at(key) = false;
  }
}

void Input::reset() {
  keysDown.clear();
  keysUp.clear();
}

std::unordered_set<KeyCode> Input::getPressedKeys() {
  std::unordered_set<KeyCode> ret;
  
  for (auto key : keysPressed) 
    if (key.second) ret.emplace(key.first);
  
  return ret;
}

void Input::inputString(std::stringstream* stream) {
  char c = 0;
  for (KeyCode key : keysDown) {
    if (key == Keys::Backspace) {
      std::string str = stream->str();
      if (str.size() == 0) return;
      
      stream->str(str.erase(str.size() - 1));
      stream->seekp(0, std::ios_base::end);
      return;

    } else if (key == Keys::Space)
      (*stream) << ' ';

    else if (!isMod(key) && key >= 33 && key <= 126) {
      c = key;
      break;
    }
  }

  if (isPressed(Keys::LShift) || isPressed(Keys::RShift)) c = std::toupper(c);
  if (c != 0) (*stream) << c;
}

bool Input::isMod(KeyCode key) {
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
