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


Vector2Int Vector2Int::copy() const {
  return { x, y };
}

Vector2 Vector2Int::toFloat() const {
  return { (float) x, (float) y };
}
