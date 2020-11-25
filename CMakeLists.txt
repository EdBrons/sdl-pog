cmake_minimum_required(VERSION 3.7)

project(rpg)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(rpg main.cpp game.cpp)
target_link_libraries(rpg PRIVATE SDL2::SDL2)