#include "Random.hpp"

float Random::range(float min, float max) {
  if (max <= min) return 0;
  return ((float) rand() / RAND_MAX) * (max - min) + min;
}

int Random::rangeInt(int min, int max) {
  if (max <= min) return 0;
  return rand() % (max - min) + min;
}

Vector2Int Random::vectorRange(Vector2Int min, Vector2Int max) {
  return Vector2Int(rangeInt(min.x, max.x), rangeInt(min.y, max.y)); 
}

Vector2 Random::vector2D() {
  return Vector2(range(-1, 1), range(-1, 1));
}

Color Random::color() {
  return color(0, 255);
}

Color Random::color(Uint8 min, Uint8 max) {
  return Color(range(min, max), range(min, max), range(min, max));
}
