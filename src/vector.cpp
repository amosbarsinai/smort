#include "vector.hpp"

Vector2::Vector2(int x, int y) : x(x), y(y) {}

std::string Vector2::to_string() {
    return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}