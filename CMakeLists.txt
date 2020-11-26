project(rpg)

cmake_minimum_required(VERSION 2.8)
set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_DIRS})

add_executable(rpg main.cpp game.cpp)
target_link_libraries(rpg ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})