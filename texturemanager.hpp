#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "game.hpp"
#include "sprite.hpp"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *file);
    static std::vector<AnimationFrame*> *LoadAnimation(const char *name, const char *json);
private:
};