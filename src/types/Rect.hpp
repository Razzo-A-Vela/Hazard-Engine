#pragma one

#include "types\Vector2.hpp"
#include "Painthandler.hpp"


struct RectInt;

struct Rect {
  Vector2 pos;
  Vector2 size;
  Rect(Vector2 pos = { 0, 0 }, Vector2 size = { 0, 0 }) : pos(pos), size(size) {}

  bool collidesWith(Vector2 other) const;
  bool collidesWith(Rect other) const;
  void render(PaintHandler* handler, bool fill = true) const { handler->drawRect(pos.toInt(), size.toInt(), fill); }
  Rect copy() const;
  RectInt toInt() const;
};

struct RectInt {
  Vector2Int pos;
  Vector2Int size;
  RectInt(Vector2Int pos = { 0, 0 }, Vector2Int size = { 0, 0 }) : pos(pos), size(size) {}

  bool collidesWith(Vector2Int other) const;
  bool collidesWith(RectInt other) const;
  void render(PaintHandler* handler, bool fill = true) const { handler->drawRect(pos, size, fill); }
  RectInt copy() const;
  Rect toFloat() const;
};
