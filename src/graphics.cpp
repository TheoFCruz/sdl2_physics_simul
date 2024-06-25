#include "graphics.hpp"

#include <SDL_render.h>
#include <iostream>

#include "world.hpp"

bool Graphics::initialize()
{
  //Creates the window
  m_window = SDL_CreateWindow("platformer",
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH,
                             SCREEN_HEIGHT,
                             SDL_WINDOW_RESIZABLE);

  if (m_window == NULL)
  {
    std::cout << "Unable to create window. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Creates the renderer
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == NULL)
  {
    std::cout << "Unable to create renderer. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Makes renderer adapt to resizing
  SDL_RenderSetLogicalSize(m_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  return true;
}

void Graphics::quit()
{
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
}

void Graphics::render(PhysicsWorld& world)
{
  SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xff);
  SDL_RenderClear(m_renderer);

  // for (const auto& object : world.getObjects()) 
  // {
  //   // Render the object
  // }

  SDL_RenderPresent(m_renderer);
}
