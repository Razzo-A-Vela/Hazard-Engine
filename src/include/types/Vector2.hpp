#pragma once
#include <cmath>

struct Vector2Int;

struct Vector2 {
  float x;
  float y;
  Vector2(float x = 0, float y = 0) : x(x), y(y) {}

  Vector2 operator+(Vector2 other) const;
  Vector2 operator+(float f) const;

  Vector2 operator-(Vector2 other) const;
  Vector2 operator-(float f) const;
  
  Vector2 operator*(Vector2 other) const;
  Vector2 operator*(float f) const;

  Vector2 operator/(Vector2 other) const;
  Vector2 operator/(float f) const;


  Vector2 normalize() const;
  float mag() const;
  Vector2 mag(float value) const;
  float dist(Vector2 other) const;

  Vector2 copy() const;
  Vector2Int toInt() const;
};

struct Vector2Int {
  int x;
  int y;
  Vector2Int(int x = 0, int y = 0) : x(x), y(y) {}

  Vector2Int operator+(Vector2Int other) const;
  Vector2Int operator+(int i) const;

  Vector2Int operator-(Vector2Int other) const;
  Vector2Int operator-(int i) const;

  Vector2Int operator*(Vector2Int other) const;
  Vector2Int operator*(int i) const;

  Vector2Int operator/(Vector2Int other) const;
  Vector2Int operator/(int i) const;

  float mag() const;
  float dist(Vector2Int other) const;

  Vector2Int copy() const;
  Vector2 toFloat() const;
};
