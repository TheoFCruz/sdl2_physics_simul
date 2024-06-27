#include "graphics.hpp"

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

  drawFilledCircle({100,100}, 20, {255,0,100,255});
  drawCircle({500, 200}, 30, {255,255,255,255});

  SDL_RenderPresent(m_renderer);
}

void Graphics::drawCircle(vec2 center, float radius, SDL_Color color)
{
  // 5/7 is a slightly biased approximation of 1/sqrt(2)
  // ((num+7) & -8) rounds num up to the nearest multiple of 8
  const int arr_size = (((int)radius * 8 * 5 / 7) + 7) & -8; 
  SDL_Point points[arr_size];
  int draw_count = 0;

  const int32_t diameter = (radius * 2);

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while( x >= y )
  {
    // Each of the following renders an octant of the circle
    points[draw_count+0] = { (int)center.x + x, (int)center.y - y };
    points[draw_count+1] = { (int)center.x + x, (int)center.y + y };
    points[draw_count+2] = { (int)center.x - x, (int)center.y - y };
    points[draw_count+3] = { (int)center.x - x, (int)center.y + y };
    points[draw_count+4] = { (int)center.x + y, (int)center.y - x };
    points[draw_count+5] = { (int)center.x + y, (int)center.y + x };
    points[draw_count+6] = { (int)center.x - y, (int)center.y - x };
    points[draw_count+7] = { (int)center.x - y, (int)center.y + x };

    draw_count += 8;

    if( error <= 0 )
    {
      ++y;
      error += ty;
      ty += 2;
    }

    if( error > 0 )
    {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }

  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawPoints(m_renderer, points, draw_count);
}

void Graphics::drawFilledCircle(vec2 center, float radius, SDL_Color color)
{
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);

  const int diameter = radius*2;
  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t dx = 1;
  int32_t dy = 1;
  int32_t error = (dx - diameter);

  while( x >= y )
  {
    SDL_RenderDrawLine(m_renderer,
                       center.x + x, center.y + y,
                       center.x - x, center.y + y);
    SDL_RenderDrawLine(m_renderer,
                       center.x + x, center.y - y,
                       center.x - x, center.y - y);
    SDL_RenderDrawLine(m_renderer,
                       center.x + y, center.y + x,
                       center.x - y, center.y + x);
    SDL_RenderDrawLine(m_renderer,
                       center.x + y, center.y - x,
                       center.x - y, center.y - x);

    if( error <= 0 )
    {
      ++y;
      error += dy;
      dy += 2;
    }

    if( error > 0 )
    {
      --x;
      dx += 2;
      error += (dx - diameter);
    }
  }
}
