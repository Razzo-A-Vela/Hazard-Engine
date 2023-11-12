#include <iostream>
#include <sstream>
#include <HazardEngine.hpp>


int main() {
  Hazard::init();
  FontHandler::addFont("Title", "comic-sans-ms.ttf", 32);
  FontHandler::addFont("Subtitle", "comic-sans-ms.ttf", 16);
  FontHandler::setDefaultFont("Title");

  Hazard::createWindow("Prova", { 500, 500 });

  static Vector2 playerPos = (Hazard::getWindowSize() / 2).toFloat();
  static const Vector2Int playerSize = { 50, 50 };
  static const float playerSpeed = 100;
  static bool showText = false;
  static std::stringstream msg;

  Hazard::onUpdate([](double deltaTime) {
    float horizontal = Input::getAxis(Axis::horizontal) * playerSpeed * deltaTime;
    float vertical = Input::getAxis(Axis::vertical) * playerSpeed * deltaTime;
    playerPos = playerPos + Vector2(horizontal, -vertical) * (Input::keyPressed(Keys::LShift) ? 2 : 1);

    if (Input::keyDown(Keys::toKeyCode('m')))
      showText = !showText;

    if (Input::keyUp(Keys::Escape))
      Hazard::quit();
  });

  Hazard::onDraw([](PaintHandler* handler) {
    handler->fillBackground(Colors::BLACK);
    handler->setColor(Colors::YELLOW);
    handler->drawRect(playerPos.toInt() - (playerSize / 2), playerSize, true);
    
    handler->setColor(Colors::WHITE);
    Vector2Int size = handler->drawText({ 0, 0 }, "FPS: " + std::to_string(Hazard::getFPS()));
    Vector2Int otherSize;

    if (showText) {
      std::stringstream pressedKeysMsg;
      pressedKeysMsg << "Pressed keys: ";

      auto keys = Input::getPressedKeys();
      for (auto key = keys.begin(); key != keys.end(); key++)
        pressedKeysMsg << Keys::toString(*key) << ", ";

      handler->setFont("Subtitle");
      otherSize = handler->drawText({ 0, size.y + 5 }, pressedKeysMsg.str());
    }

    Input::inputString(&msg);
    handler->drawText({ 0, size.y + otherSize.y + 10 }, "Chars: " + msg.str());
    handler->setColor(Input::mousePressed(1) ? Colors::BLUE : Colors::RED);
    handler->drawRect(Input::getMousePos() - 5, { 10, 10 }, true);
  });

  Hazard::onQuit([]() {
    std::cout << "Bye!\n";
  });

  Hazard::run();
  Hazard::quit();
  return EXIT_SUCCESS;
}
