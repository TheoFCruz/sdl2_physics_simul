#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <vector>

#include "object.hpp"
#include "physics.hpp"
#include "graphics.hpp"

const int BOUND_RADIUS = 250;
const vec2 BOUND_CENTER = {(float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2};

class PhysicsWorld
{
public:
  PhysicsWorld(): m_physics(*this) {}
  ~PhysicsWorld() = default;

  bool initialize();
  void quit();

  void update(double dt); 

  std::vector<PhysicsObject>& getObjects() { return m_objects; }

private:
  PhysicsManager m_physics; 

  std::vector<PhysicsObject> m_objects;
};

#endif // !PHYSICS_WORLD_H
