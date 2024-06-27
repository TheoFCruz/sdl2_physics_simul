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

  m_objects.push_back(PhysicsObject({250,250}));

  return true;
}

void PhysicsWorld::quit()
{
  SDL_Quit();
}

void PhysicsWorld::update(double dt)
{
  // Update physics manager
  m_physics.update(dt);
}
