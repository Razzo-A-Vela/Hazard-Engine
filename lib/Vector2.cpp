#include "types\Vector2.hpp"

Vector2 Vector2::operator+(Vector2 other) const {
  Vector2 ret = copy();
  ret.x += other.x;
  ret.y += other.y;
  return ret;
}

Vector2 Vector2::operator+(float f) const {
  return (*this) + Vector2(f, f);
}

Vector2 Vector2::operator-(Vector2 other) const {
  Vector2 ret = copy();
  ret.x -= other.x;
  ret.y -= other.y;
  return ret;
}

Vector2 Vector2::operator-(float f) const {
  return (*this) - Vector2(f, f);
}

Vector2 Vector2::operator*(Vector2 other) const {
  Vector2 ret = copy();
  ret.x *= other.x;
  ret.y *= other.y;
  return ret;
}

Vector2 Vector2::operator*(float f) const {
  return (*this) * Vector2(f, f);
}

Vector2 Vector2::operator/(Vector2 other) const {
  Vector2 ret = copy();
  ret.x /= other.x;
  ret.y /= other.y;
  return ret;
}

Vector2 Vector2::operator/(float f) const {
  return (*this) / Vector2(f, f);
}


Vector2 Vector2::normalize() const {
  float m = mag();
  return m != 0 ? copy() / m : Vector2();
}

float Vector2::mag() const {
  return sqrt(x*x + y*y);
}

Vector2 Vector2::mag(float value) const {
  return normalize() * value;
}

float Vector2::dist(Vector2 other) const {
  float xx = (other.x - x);
  float yy = (other.y - y);
  xx *= xx;
  yy *= yy;
  
  return sqrt(xx + yy);
}

Vector2 Vector2::copy() const {
  return { x, y };
}

Vector2Int Vector2::toInt() const {
  return { (int) x, (int) y };
}



Vector2Int Vector2Int::operator+(Vector2Int other) const {
  Vector2Int ret = copy();
  ret.x += other.x;
  ret.y += other.y;
  return ret;
}

Vector2Int Vector2Int::operator+(int i) const {
  return (*this) + Vector2Int(i, i);
}

Vector2Int Vector2Int::operator-(Vector2Int other) const {
  Vector2Int ret = copy();
  ret.x -= other.x;
  ret.y -= other.y;
  return ret;
}

Vector2Int Vector2Int::operator-(int i) const {
  return (*this) - Vector2Int(i, i);
}

Vector2Int Vector2Int::operator*(Vector2Int other) const {
  Vector2Int ret = copy();
  ret.x *= other.x;
  ret.y *= other.y;
  return ret;
}

Vector2Int Vector2Int::operator*(int i) const {
  return (*this) * Vector2Int(i, i);
}

Vector2Int Vector2Int::operator/(Vector2Int other) const {
  Vector2Int ret = copy();
  ret.x /= other.x;
  ret.y /= other.y;
  return ret;
}

Vector2Int Vector2Int::operator/(int i) const {
  return (*this) / Vector2Int(i, i);
}


float Vector2Int::mag() const {
  return sqrt(x*x + y*y);
}

float Vector2Int::dist(Vector2Int other) const {
  int xx = (other.x - x);
  int yy = (other.y - y);
  xx *= xx;
  yy *= yy;
  
  return sqrt(xx + yy);
}

Vector2Int Vector2Int::copy() const {
  return { x, y };
}

Vector2 Vector2Int::toFloat() const {
  return { (float) x, (float) y };
}
