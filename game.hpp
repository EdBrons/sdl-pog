#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "texturemanager.hpp"
#include "sprite.hpp"

class Game 
{
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);

    void handleEvents();
    void update(int delta);
    bool running() { return isRunning; }
    void render();
    void clean();

    static SDL_Texture *SpriteSheet;
    static std::map<std::string, std::vector<SDL_Rect*>*> *Animations;
    static SDL_Renderer *Renderer;
    static Sprite *sprite;
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};