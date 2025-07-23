#include <SFML/Graphics.hpp>

#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

#include "common.hpp"
#include "error.hpp"
#include "vector.hpp"

std::unordered_map<std::string, sf::Texture> texture_cache;

bool assert_valid_float(float value) {
    return value >= 0.0f && value <= 1.0f;
}

bool silent_load(sf::Texture& texture, const std::string& path) {
    // Flush stderr
    fflush(stderr);

    // Save old stderr fd
    int old_stderr_fd = dup(fileno(stderr));
    if (old_stderr_fd == -1) return false;

    // Redirect stderr to /dev/null
    int dev_null = open("/dev/null", O_WRONLY);
    if (dev_null == -1) {
        close(old_stderr_fd);
        return false;
    }
    dup2(dev_null, fileno(stderr));
    close(dev_null);

    // Now call loadFromFile silently
    bool result = texture.loadFromFile(path);

    // Restore stderr
    fflush(stderr);
    dup2(old_stderr_fd, fileno(stderr));
    close(old_stderr_fd);

    return result;
}

Vector2 get_size(const std::string& image) {
    sf::Texture& texture = texture_cache[image];
    if (texture.getSize().x == 0) {
        if (!silent_load(texture, image)) {
            imgloaderr(image);
        }
    }
    return Vector2(texture.getSize().x, texture.getSize().y);
}

int get_width(const std::string& image) {
    sf::Texture& texture = texture_cache[image];
    if (texture.getSize().x == 0) {
        if (!silent_load(texture, image)) {
            imgloaderr(image);
        }
    }
    return texture.getSize().x;
}

int get_height(const std::string& image) {
    sf::Texture& texture = texture_cache[image];
    if (texture.getSize().x == 0) {
        if (!silent_load(texture, image)) {
            imgloaderr(image);
        }
    }
    return texture.getSize().y;
}
