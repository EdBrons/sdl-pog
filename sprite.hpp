#pragma once
#include <SDL2/SDL.h>
#include <vector>

#define ANIMATION_TIME 1000

class Sprite {
public:
    Sprite();
    ~Sprite();
    void update(int delta);
    void render(SDL_Renderer *renderer, SDL_Texture *texture);
    void play_animation(std::vector<SDL_Rect*>*);
private:
    int animation_timer;
    SDL_Texture *spritesheet;
    std::vector<SDL_Rect*>* loop;
    SDL_Rect *srect;
    SDL_Rect *drect;
};