#pragma once

struct Vector2 {
  Vector2(float x = 0, float y = 0) : x(x), y(y) {}

  float x;
  float y;
};

struct Vector2Int {
  Vector2Int(int x = 0, int y = 0) : x(x), y(y) {}

  int x;
  int y;
};
