#pragma once
#include <SDL2/SDL.h>
#include "texturemanager.hpp"

class Sprite 
{
public:
    Sprite();
    ~Sprite();
    void update();
    void render(SDL_Renderer *renderer);
private:
};