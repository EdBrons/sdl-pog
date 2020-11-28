#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include "game.hpp"
#include "json.hpp"

class TextureManager {
    public:
    static SDL_Texture *LoadTexture(const char *file);
    static std::vector<SDL_Rect*> *GetAnimation(std::string name);
    static std::map<std::string, std::vector<SDL_Rect*>*> *LoadSpriteSheet(const char *file, const char *json);
    private:
    static std::map<std::string, std::vector<SDL_Rect*>*> *TextureMap;
};