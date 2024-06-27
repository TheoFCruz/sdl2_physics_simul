#ifndef MATH_H
#define MATH_H

#include <cassert>
#include <cmath>

struct vec2
{
  float x;
  float y;

  vec2(): x(0), y(0) {}
  vec2(float px, float py): x(px), y(py) {}

  float length() { return sqrt(x*x + y*y); }

  // Overloads
  
  vec2 operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
  vec2 operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
  vec2 operator*(float scalar) const { return vec2(x * scalar, y * scalar); }
  vec2 operator/(float scalar) const {
    assert(scalar != 0);
    return vec2(x / scalar, y / scalar);
  }

  vec2& operator+=(const vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  vec2& operator-=(const vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
};

#endif // !MATH_H
