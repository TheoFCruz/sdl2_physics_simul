#include "physics.hpp"

#include "world.hpp"

void PhysicsManager::update(double dt)
{
  const double step_dt = dt/STEPS;
  for (int i = 0; i < STEPS; i++)
  {
    for (PhysicsObject& object : m_world.getObjects())
    {
      object.applyAcceleration(GRAVITY);
      applyBounds(object);
      object.update(step_dt);
    }
  }
}

void PhysicsManager::applyBounds(PhysicsObject& object)
{
  vec2 displacement = BOUND_CENTER - object.getPosition();  
  float distance = displacement.length(); 

  if (distance > BOUND_RADIUS - object.getRadius())
  {
    vec2 normal = displacement/distance;
    object.move(normal * (distance - (BOUND_RADIUS - object.getRadius())));
    // object.applyForce(normal*100000);
  }
}
