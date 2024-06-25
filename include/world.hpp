#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <vector>

#include "object.hpp"
#include "physics.hpp"
#include "graphics.hpp"

class PhysicsWorld
{
public:
  PhysicsWorld() {}
  ~PhysicsWorld() {}

  bool initialize();
  void update(double dt); 

  std::vector<PhysicsObject>& getObjects() { return m_objects; }

private:
  PhysicsManager m_physics; 

  std::vector<PhysicsObject> m_objects;
};

#endif // !PHYSICS_WORLD_H
