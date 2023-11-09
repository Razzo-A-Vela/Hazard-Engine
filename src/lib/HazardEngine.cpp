#include "HazardEngine.hpp"

void Hazard::init() {
  if (initialized) return;
  std::cout << "Initializing Hazard Engine...\n";
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  Input::init();
  initialized = true;
}

void Hazard::createWindow(std::string title, Vector2Int size) {
  Hazard::init();
  std::cout << "Window size: " << size.x << ", " << size.y << "\n";

  SDL_Window* sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
  SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  window = new Window{size, sdl_window, renderer};
}

void Hazard::quit() {
  quitFunc();
  FontHandler::close();
  SDL_DestroyRenderer(window->renderer);
  SDL_DestroyWindow(window->window);
  SDL_Quit();
  TTF_Quit();
  exit(EXIT_SUCCESS);
}

void Hazard::run() {
  SDL_Event e;
  bool quit = false;

  int frames = 0;
  float timePassed = 0;

  while (!quit) {
    auto start = std::chrono::system_clock::now();

    Input::reset();
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) quit = true;
      else Input::update(&e);
    }
    updateFunc(deltaTime);

    PaintHandler handler = PaintHandler(window);
    drawFunc(&handler);
    SDL_RenderPresent(window->renderer);

    auto end = std::chrono::system_clock::now();
    deltaTime = ((std::chrono::duration<double>)(end - start)).count();

    frames++;
    timePassed += deltaTime;
    if (timePassed >= 1) {
      fps = frames;
      frames = 0;
      timePassed = 0;
    }
  }

  Hazard::quit();
}
