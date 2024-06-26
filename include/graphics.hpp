#ifndef GRAPHICS_H
#define GRAPHICS_H 

#include "math.hpp"
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
  void drawCircle(vec2 position, float radius, SDL_Color color);

  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
};

#endif // !GRAPHICS_H
