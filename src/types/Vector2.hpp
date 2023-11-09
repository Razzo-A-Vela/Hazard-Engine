#pragma once

struct Vector2 {
  float x;
  float y;
  Vector2(float x = 0, float y = 0) : x(x), y(y) {}

  Vector2 operator+(Vector2 other) {
    Vector2 ret = copy();
    ret.x += other.x;
    ret.y += other.y;
    return ret;
  }

  Vector2 operator+(float f) {
    return (*this) + Vector2(f, f);
  }

  Vector2 operator-(Vector2 other) {
    Vector2 ret = copy();
    ret.x -= other.x;
    ret.y -= other.y;
    return ret;
  }

  Vector2 operator-(float f) {
    return (*this) - Vector2(f, f);
  }

  Vector2 copy() {
    return Vector2(x, y);
  }
};

struct Vector2Int {
  int x;
  int y;
  Vector2Int(int x = 0, int y = 0) : x(x), y(y) {}

  Vector2Int operator+(Vector2Int other) {
    Vector2Int ret = copy();
    ret.x += other.x;
    ret.y += other.y;
    return ret;
  }

  Vector2Int operator+(int i) {
    return (*this) + Vector2Int(i, i);
  }

  Vector2Int operator-(Vector2Int other) {
    Vector2Int ret = copy();
    ret.x -= other.x;
    ret.y -= other.y;
    return ret;
  }

  Vector2Int operator-(int i) {
    return (*this) - Vector2Int(i, i);
  }

  Vector2Int copy() {
    return Vector2Int(x, y);
  }
};
