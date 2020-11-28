#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "texturemanager.hpp"
#include "sprite.hpp"

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
    Sprite *makeSprite();
    void removeSprite(Sprite*);
    std::vector<Sprite*> *sprites;

    bool isRunning;
    SDL_Window *window;
};