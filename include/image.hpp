#pragma once

#include <string>

#include "vector.hpp"

#include <SFML/Graphics.hpp>

class Image {
  public:
    Image(const std::string &filePath);
    ~Image();

    int get_width() const;
    int get_height() const;
    Vector2 get_size() const;

    int width;
    int height;
    
    sf::Texture* texture;

    std::string to_string();

  void blit(Image& src, int x, int y, int width, int height);
  void blit(Image& src, int x, int y);
  void blit(Image& src);
};
