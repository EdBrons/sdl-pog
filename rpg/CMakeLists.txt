cmake_minimum_required(VERSION 3.7)

project(rpg)

find_package(SDL2 REQUIRED)

add_executable(rpg main.cpp game.cpp)
target_link_libraries(rpg PRIVATE SDL2::SDL2)