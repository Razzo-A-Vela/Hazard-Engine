#include "types\Rect.hpp"


bool Rect::collidesWith(Vector2 other) const {
  return other.x >= pos.x && other.x < pos.x + size.x &&
         other.y >= pos.y && other.y < pos.y + size.y;
}

bool Rect::collidesWith(Rect other) const {
  bool thisToOther = collidesWith(other.pos) || collidesWith(other.pos + Vector2(other.size.x, 0)) ||
    collidesWith(other.pos + Vector2(0, other.size.y)) || collidesWith(other.pos + Vector2(other.size.x, other.size.y));
  bool otherToThis = other.collidesWith(pos) || other.collidesWith(pos + Vector2(size.x, 0)) ||
    other.collidesWith(pos + Vector2(0, size.y)) || other.collidesWith(pos + Vector2(size.x, size.y));

  return thisToOther || otherToThis;
}

Rect Rect::copy() const {
  return { pos, size };
}

RectInt Rect::toInt() const {
  return { pos.toInt(), size.toInt() };
}



bool RectInt::collidesWith(Vector2Int other) const {
  return other.x >= pos.x && other.x < pos.x + size.x &&
         other.y >= pos.y && other.y < pos.y + size.y;
}

bool RectInt::collidesWith(RectInt other) const {
  return collidesWith(other.pos) || collidesWith(other.pos + Vector2Int(other.size.x, 0)) ||
         collidesWith(other.pos + Vector2Int(0, other.size.y)) || collidesWith(other.pos + Vector2Int(other.size.x, other.size.y));
}

RectInt RectInt::copy() const {
  return { pos, size };
}

Rect RectInt::toFloat() const {
  return { pos.toFloat(), size.toFloat() };
}
