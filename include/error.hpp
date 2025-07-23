#pragma once
#include <stdexcept>

class SmortImageError : public std::runtime_error {
    public:
        explicit SmortImageError(const std::string& path);
};

inline constexpr const char* YELLOW = "\033[33m";
inline constexpr const char* ORANGE = "\033[38;5;208m";
inline constexpr const char* BOLD = "\033[1m";
inline constexpr const char* ANSII_RESET = "\033[0m";

void err(const std::string& msg);

void imgloaderr(const std::string& path);