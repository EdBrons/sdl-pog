#pragma once
#include <iostream>
#include <fstream>
#include "game.hpp"
#include "json.hpp"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *file);
    // static std::vector<AnimationFrame> *LoadAnimation(const char *name, const char *jsonfile);
private:
};