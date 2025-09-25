#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "image.hpp"
#include "vector.hpp"

class Window {
public:
    // Single constructor with defaults
    Window(
        const std::string& title,
        int width,
        int height,
        bool handles_updates,
        float target_delta
    );

    // Property accessors for title
    std::string get_title() const;
    void set_title(const std::string& title);

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

    void display();
};
