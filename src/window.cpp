// src/window.cpp
#include "window.hpp"

#include "error.hpp"
#include "common.hpp"

#include "smort_meme.hpp"

#include <chrono>
#include <thread>

Window::Window(const std::string& title, int width, int height, bool handles_updates, int target_delta)
    : window(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close),
    target_delta(target_delta), handles_updates(handles_updates) {}

void Window::clear() {
    window.clear();
}

void Window::display() {
    window.display();
}

void Window::tick() {
    static sf::Clock clock;
    float elapsed = clock.getElapsedTime().asSeconds();

    if (elapsed < target_delta && handles_updates) {
        std::this_thread::sleep_for(std::chrono::duration<float>(target_delta - elapsed));
    }

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    display();

    delta_time = clock.restart().asSeconds();
}


bool Window::is_open() {
    return window.isOpen();
}

void Window::set_fps(float fps) {
    target_delta = 1.0f / fps;
}

void Window::fill(float r, float g, float b) {
    if (!assert_valid_float(r)) {
        throw SmortImageError("Invalid float value for red channel: " + std::to_string(r));
    }
    if (!assert_valid_float(g)) {
        throw SmortImageError("Invalid float value for green channel: " + std::to_string(g));
    }
    if (!assert_valid_float(b)) {
        throw SmortImageError("Invalid float value for blue channel: " + std::to_string(b));
    }
    window.clear(sf::Color(
        static_cast<uint8_t>(r * 255),
        static_cast<uint8_t>(g * 255),
        static_cast<uint8_t>(b * 255)
    ));
}

void Window::fill(int r, int g, int b) {
    window.clear(sf::Color(r, g, b));
}
// Note: The fill methods allow for both float and int color values, converting float to uint8_t for SFML compatibility.
// The fill methods are overloaded to accept either float or int values for RGB colors.

void Window::blit(const std::string& path, float x, float y) {
    sf::Texture& texture = texture_cache[path];
    if (texture.getSize().x == 0) {
        if (!silent_load(texture, path)) {
            imgloaderr(path);
        }
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    window.draw(sprite);
}

void Window::blit(const std::string& path, float x, float y, float width, float height) {
    sf::Texture& texture = texture_cache[path];
    if (texture.getSize().x == 0) {
        if (!silent_load(texture, path)) {
            imgloaderr(path);
        }
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    sprite.setScale(
        width / texture.getSize().x,
        height / texture.getSize().y
    );
    window.draw(sprite);
}

// Note: The blit methods load the texture from the specified path if it is not already cached.
// The first blit method draws the texture at the specified position, while the second one scales the texture to the specified width and height before drawing it.
// The texture is cached in a static unordered_map to avoid reloading it multiple times, improving performance.

void Window::blit(Image& image, float x, float y) {
    sf::Texture& texture = *image.texture;

    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    window.draw(sprite);
}

void Window::blit(Image& image, float x, float y, float width, float height) {
    sf::Texture& texture = *image.texture;
    
    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    sprite.setScale(
        width / texture.getSize().x,
        height / texture.getSize().y
    );
    window.draw(sprite);
}



void Window::close() {
    window.close();
}

int Window::get_width() const {
    return window.getSize().x;
}

void Window::set_width(int new_width) {
    if (new_width < 1) return; // ignore invalid sizes or clamp as needed
    window.setSize(sf::Vector2u(new_width, window.getSize().y));
}

int Window::get_height() const {
    return window.getSize().y;
}

void Window::set_height(int new_height) {
    if (new_height < 1) return;
    window.setSize(sf::Vector2u(window.getSize().x, new_height));
}

Vector2 Window::get_size() const {
    sf::Vector2u size = window.getSize();
    return Vector2(size.x, size.y);
}

void Window::set_size(Vector2 new_size) {
    if (new_size.x < 1 || new_size.y < 1) err("Cannot resize window to dimensions under 1px.");
    window.setSize(sf::Vector2u(new_size.x, new_size.y));
}

void Window::smort() {
    sf::Texture texture;
    if (!texture.loadFromMemory(smort_jpg, smort_jpg_len)) {
        throw SmortImageError("Failed to load embedded SMORT image.");
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(42.f, 42.f);
    sprite.setScale(0.5f, 0.5f);
    window.draw(sprite);
}

std::string Window::to_string() {
    return "Window(" + std::to_string(get_width()) + "x" + std::to_string(get_height()) + ")";
}
