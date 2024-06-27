#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include "math.hpp"
#include "object.hpp"

class PhysicsWorld;

const vec2 GRAVITY = {0, 1000};
const int STEPS = 8;

class PhysicsManager
{
public:
  PhysicsManager() = delete;
  PhysicsManager(PhysicsWorld& world): m_world(world) {}
  ~PhysicsManager() = default;

  void update(double dt);

private:
  void applyBounds(PhysicsObject& object);

  PhysicsWorld& m_world;  
};

#endif // !PHYSICS_MANAGER_H
