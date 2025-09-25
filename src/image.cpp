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

void Image::blit(Image& src, int x, int y, int width, int height) {
    if (width < 0)
        err("Cannot scale image to negative values. (Tried scaling width to " + std::to_string(width) + ")");
    if (height < 0)
        err("Cannot scale image to negative values. (Tried scaling height to " + std::to_string(height) + ")");

    int srcWidth = (width > 0) ? width : src.width;
    int srcHeight = (height > 0) ? height : src.height;

    sf::RenderTexture renderTexture;
    renderTexture.create(this->width, this->height);
    renderTexture.clear(sf::Color::Transparent);

    sf::Sprite destSprite(*this->texture);
    renderTexture.draw(destSprite);

    sf::Sprite srcSprite(*src.texture);
    srcSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    // Scale if needed
    float scaleX = static_cast<float>(srcWidth) / static_cast<float>(src.width);
    float scaleY = static_cast<float>(srcHeight) / static_cast<float>(src.height);
    srcSprite.setScale(scaleX, scaleY);

    renderTexture.draw(srcSprite);
    renderTexture.display();

    this->texture->update(renderTexture.getTexture());
}

void Image::blit(Image& src, int x, int y) {
    blit(src, x, y, src.get_width(), src.get_height());
}

void Image::blit(Image& src) {
    blit(src, 0, 0);
}
