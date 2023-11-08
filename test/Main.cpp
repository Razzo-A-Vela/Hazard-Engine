#include <iostream>
#include <HazardEngine.hpp>


int main() {
  Hazard::init();
  FontHandler::addFont("Title", "comic-sans-ms.ttf", 32);
  FontHandler::addFont("Subtitle", "comic-sans-ms.ttf", 16);
  FontHandler::setDefaultFont("Title");

  Hazard::createWindow("Prova", Vector2Int(500, 500));
  static float x = 0;

  Hazard::onUpdate([](double deltaTime) {
    x += deltaTime * 10;
  });

  Hazard::onDraw([](PaintHandler* handler) {
    handler->fillBackground(Colors::BLACK);
    handler->setColor(Colors::WHITE);
    handler->drawRect(Vector2Int(250 + x, 250), Vector2Int(100, 100), true);

    Vector2Int size = handler->drawText(Vector2Int(0, 0), "FPS: " + std::to_string(Hazard::getFPS()));
    handler->setFont("Subtitle");
    handler->drawText(Vector2Int(0, size.y + 5), "MMMMM");
  });

  Hazard::onQuit([]() {
    std::cout << "Bye!\n";
  });

  Hazard::run();
  return EXIT_SUCCESS;
}
