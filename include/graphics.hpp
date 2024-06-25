#ifndef GRAPHICS_H
#define GRAPHICS_H 

#include <SDL.h>

class PhysicsWorld;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Graphics
{
public:
  Graphics() = default;
  ~Graphics() = default;

  bool initialize();
  void quit();

  void render(PhysicsWorld& world);

private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
};

#endif // !GRAPHICS_H
