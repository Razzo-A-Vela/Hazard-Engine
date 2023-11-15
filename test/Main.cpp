#include <iostream>
#include <sstream>
#include <HazardEngine.hpp>


int main() {
  Hazard::init();
  FontHandler::addFont("", ".\\comic-sans-ms.ttf", 32);

  Hazard::createWindow("Prova", { 500, 500 });
  static Rect player = { (Hazard::getWindowSize() / 2).toFloat(), { 50, 50 } };
  player.pos = player.pos - player.size / 2.0f;
  static RectInt mouse = { { 0, 0 }, { 10, 10 } };
  static const RectInt otherRect = { { 250, 100 }, { 100, 100 } };

  Hazard::onUpdate([](double deltaTime) {
    float horizontal = Input::getAxis(Axis::horizontal);
    float vertical = Input::getAxis(Axis::vertical);
    player.pos = player.pos + Vector2(horizontal, -vertical) * 150 * deltaTime;

    mouse.pos = Input::getMousePos() - (mouse.size / 2);
    
    if (Input::keyDown(Keys::Escape)) 
      Hazard::quit(1);
  });

  Hazard::onDraw([](PaintHandler* handler) {
    handler->fillBackground(Colors::BLACK);

    if (player.collidesWith(otherRect.toFloat()))
      handler->setColor(Colors::BLUE);
    else
      handler->setColor(Colors::CYAN);
    otherRect.render(handler, true);

    handler->setColor(Colors::YELLOW);
    player.render(handler, true);

    handler->setColor(Colors::WHITE);
    handler->drawText({ 0, 0 }, "FPS: " + std::to_string(Hazard::getFPS()));

    handler->setColor(Colors::RED);
    mouse.render(handler);
  });

  Hazard::run();
  Hazard::quit();
}
