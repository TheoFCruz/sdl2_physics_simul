#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H 

#include "math.hpp"

class PhysicsObject
{
public:
  PhysicsObject();
  ~PhysicsObject();

  void update(double dt);

  // void applyForce(vec2 force) { m_acceleration += force/m_mass; }
  // void applyAcceleration(vec2 accel) { m_acceleration += accel; };

private:
  float m_radius =  10.0f;
  float m_mass = 1.0f;

  vec2 m_position;
  vec2 m_velocity;
  vec2 m_acceleration;
};

#endif // !PHYSICS_OBJECT_H
