#pragma once
#include <cstdlib>
#include <ctime>

#include "types\Vector2.hpp"
#include "types\Color.hpp"


class Random {
public:
  static void init() { srand(time(NULL)); }
  static float range(float min, float max);
  static int rangeInt(int min, int max);
  static Vector2Int vectorRange(Vector2Int min, Vector2Int max);
  static Vector2 vector2D();
  static Color color();
  static Color color(Uint8 min, Uint8 max);

private:
};
