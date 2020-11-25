cmake_minimum_required(VERSION 2.8)
project(rpg)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})


add_executable(rpg main.cpp game.cpp)
target_link_libraries(rpg ${SDL2_LIBRARY})