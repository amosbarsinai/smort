#include "error.hpp"

SmortImageError::SmortImageError(const std::string& msg)
    : std::runtime_error(msg) {}

void imgloaderr(const std::string& path) {
    throw SmortImageError(
                            "Failed to load image from '" +
                            path +
                            "'. Ensure the file exists and is a valid image format."
                        );
}