#include <SDL2/SDL.h>

#include "world.hpp"
#include "graphics.hpp"

int main (int argc, char** argv)
{
  PhysicsWorld world;
  Graphics graphics;

  if (!world.initialize()) return -1;
  if (!graphics.initialize()) return -1;

  Uint64 current_counter = SDL_GetPerformanceCounter();
  Uint64 last_counter = 0;
  double delta_time = 0;

  SDL_Event event;
  bool running = true;
  while (running)
  {
    // Calculates delta_time in milliseconds
    last_counter = current_counter;
    current_counter = SDL_GetPerformanceCounter();
    delta_time = ((double)(current_counter - last_counter))/((double)(SDL_GetPerformanceFrequency()));

    // Event loop
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) running = false;
    }

    //Game update and draw
    world.update(delta_time);
    graphics.render(world);
  }

  graphics.quit();
  world.quit();
}
