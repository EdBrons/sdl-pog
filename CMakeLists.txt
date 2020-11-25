# cmake_minimum_required(VERSION 2.8)
# project(rpg)

# # includes cmake/FindSDL2.cmake
# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIR})


# add_executable(rpg main.cpp game.cpp)
# target_link_libraries(rpg ${SDL2_LIBRARY})

project(rpg)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(${PROJECT_NAME} main.cpp game.cpp)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})