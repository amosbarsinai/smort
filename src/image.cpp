#include "image.hpp"
#include "common.hpp"
#include "error.hpp"

Image::Image(const std::string &file_path) {
    // silent load image
    if (!silent_load(texture_cache[file_path], file_path)) {
        imgloaderr(file_path);
    }
    this->width = texture_cache[file_path].getSize().x;
    this->height = texture_cache[file_path].getSize().y;
    this->texture = &texture_cache[file_path];
}

int Image::get_height() const {
    return height;
}

int Image::get_width() const {
    return height;
}

Vector2 Image::get_size() const {
    return Vector2(width, height);
}

Image::~Image() {
    // texture is managed by texture_cache, do nothing
}

std::string Image::to_string() {
    return "Image(" + std::to_string(width) + "x" + std::to_string(height) + ")";
}