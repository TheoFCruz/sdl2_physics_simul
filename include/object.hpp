#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H 

#include "math.hpp"
#include <SDL_pixels.h>

class PhysicsObject
{
public:
  PhysicsObject() = default;
  PhysicsObject(vec2 position): m_position(position), m_last_position(position) {}
  PhysicsObject(float radius, float mass, vec2 position):
    m_radius(radius),
    m_mass(mass),
    m_position(position),
    m_last_position(position) {}

  ~PhysicsObject() = default;

  void update(double dt);

  void move(vec2 displacement) { m_position += displacement; }
  void applyForce(vec2 force) { m_acceleration += force/m_mass; }
  void applyAcceleration(vec2 accel) { m_acceleration += accel; };

  float getRadius() { return m_radius; }

  vec2 getPosition() { return m_position; }
  vec2 getVel() { return m_velocity; }
  vec2 getAccel() { return m_acceleration; }

  SDL_Color getColor() { return m_color; }
private:
  float m_radius =  20.0f;
  float m_mass = 1.0f;

  vec2 m_position;
  vec2 m_last_position;
  vec2 m_velocity = {0, 0};
  vec2 m_acceleration = {0, 0};

  SDL_Color m_color = {0xff, 0x00, 0x00, 0xff};
};

#endif // !PHYSICS_OBJECT_H
