#include "world.hpp"

#include <iostream>

bool PhysicsWorld::initialize()
{
  // Initializes SDL, SDL_image and SDL_ttf
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    std::cout << "Unable to init SDL. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}

void PhysicsWorld::quit()
{
  SDL_Quit();
}

void PhysicsWorld::update(double dt)
{
  // Update each object
  // Update physics manager
}
