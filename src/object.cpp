#include "object.hpp"

void PhysicsObject::update(double dt)
{
  // m_position += m_velocity * dt;
  // m_velocity += m_acceleration * dt;
  
  vec2 displacement = m_position - m_last_position;

  m_last_position = m_position;
  m_position = m_position + displacement + m_acceleration * dt * dt;

  m_acceleration = {0, 0};
}
