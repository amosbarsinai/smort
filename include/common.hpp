#pragma once

#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "vector.hpp"

bool assert_valid_float(float value);

bool silent_load(sf::Texture& texture, const std::string& path);

extern std::unordered_map<std::string, sf::Texture> texture_cache;

void add_texture(const std::string& path);
void get_texture(const std::string& path);