// include/window.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "image.hpp"
#include "vector.hpp"

class Window {
public:
    Window(const std::string& title);
    Window(const std::string& title, int width, int height);
    Window(const std::string& title, int width, int height, bool handles_updates);
    void clear();
    void tick();
    bool is_open();

    void fill(float r, float g, float b);
    void fill(int r, int g, int b);

    void blit(const std::string& path, float x, float y);
    void blit(const std::string& path, float x, float y, float width, float height);

    void blit(Image& image, float x, float y);
    void blit(Image& image, float x, float y, float width, float height);

    void set_fps(float fps);

    void close();

    int get_width() const;
    void set_width(int new_width);

    int get_height() const;
    void set_height(int new_height);

    Vector2 get_size() const;
    void set_size(Vector2 new_size);

    void smort();

    std::string to_string();

private:
    sf::RenderWindow window;

    bool handles_updates;

    float delta_time = 0.0f;
    float target_delta = 1.0f / 60.0f;
    float get_delta_time() const { return delta_time; }
    
    void display();
};
