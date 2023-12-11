cmake_minimum_required(VERSION 3.22)

project(
    AOC23
    DESCRIPTION "Advent of Code 2023"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy --checks=-*,bugprone-*,misc-*,performance-*,-misc-no-recursion --use-color)

add_compile_options(-fsanitize=address -ggdb -O0)
add_link_options(-fsanitize=address)

enable_testing()

add_subdirectory(src)
add_subdirectory(utils)
add_subdirectory(test)

