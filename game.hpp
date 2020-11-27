#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>

class Game 
{
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);

    void handleEvents();
    void update();
    bool running() { return running; }
    void render();
    void clean();

    static SDL_Renderer *Renderer;
private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
};