#include <iostream>
#include <sstream>
#include <HazardEngine.hpp>


int main() {
  Hazard::init();
  FontHandler::addFont("Title", "comic-sans-ms.ttf", 32);
  FontHandler::addFont("Subtitle", "comic-sans-ms.ttf", 16);
  FontHandler::setDefaultFont("Title");
  
  Hazard::createWindow("Prova", Vector2Int(500, 500));
  static float x = 0;
  static bool showText = false;
  static std::stringstream msg;

  Hazard::onUpdate([](double deltaTime) {
    if (Input::isPressed(Keys::Space))
      x += deltaTime * 10 * (Input::isPressed(Keys::LShift) ? 10 : 1);

    if (Input::keyDown(Keys::toKeyCode('r')))
      x = 0;

    if (Input::keyDown(Keys::toKeyCode('m')))
      showText = !showText;

    if (Input::keyUp(Keys::Escape))
      Hazard::quit(); 
  });

  Hazard::onDraw([](PaintHandler* handler) {
    handler->fillBackground(Colors::BLACK);
    handler->setColor(Colors::WHITE);
    handler->drawRect(Vector2Int(250 + x, 250), Vector2Int(100, 100), true);
    Vector2Int size = handler->drawText(Vector2Int(0, 0), "FPS: " + std::to_string(Hazard::getFPS()));
    Vector2Int otherSize;

    if (showText) {
      std::stringstream pressedKeysMsg;
      pressedKeysMsg << "Pressed keys: ";

      auto keys = Input::getPressedKeys();
      for (auto key = keys.begin(); key != keys.end(); key++)
        pressedKeysMsg << Keys::toString(*key) << ", ";

      handler->setFont("Subtitle");
      otherSize = handler->drawText(Vector2Int(0, size.y + 5), pressedKeysMsg.str());
    }

    Input::inputString(&msg);
    handler->drawText(Vector2Int(0, size.y + otherSize.y + 10), "Chars: " + msg.str());
  });

  Hazard::onQuit([]() {
    std::cout << "Bye!\n";
  });

  Hazard::run();
  return EXIT_SUCCESS;
}
