cmake_minimum_required(VERSION 3.15)
project(smort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
include(CTest)

# ─── Fetch SFML ──────────────────────────────────────────────
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1  # You can change this to latest
)

FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.12.0  # Or latest stable
)

# Prevent SFML from building examples, tests, audio if not needed
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(pybind11)

# ─── pybind11 ────────────────────────────────────────────────
pybind11_add_module(_smort
    src/bindings.cpp
    src/window.cpp
    src/error.cpp
    src/common.cpp
    src/vector.cpp
    src/image.cpp
)

# ─── Build Module ────────────────────────────────────────────
target_include_directories(_smort PRIVATE include)
target_link_libraries(_smort PRIVATE sfml-graphics sfml-window sfml-system)

set_target_properties(_smort PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/smort
)
