#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "texturemanager.hpp"

class Game 
{
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render(int delta);
    void clean();

    static SDL_Renderer *Renderer;
    static SDL_Texture *SpriteSheet;
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};