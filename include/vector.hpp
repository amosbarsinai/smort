#pragma once

#include <string>

class Vector2 {
  public:
    int x;
    int y;
    Vector2(int x, int y);
    std::string to_string();
};