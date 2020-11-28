#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"

struct AnimationFrame {
    int id;
    int time;
    SDL_Rect *srect;
    AnimationFrame *next;
};

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *file);
    static AnimationFrame *LoadAnimation(const char *name, const char *jsonfile);
private:
};