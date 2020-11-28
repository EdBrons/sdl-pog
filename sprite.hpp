#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct AnimationFrame
{
    SDL_Rect srect;
    int duration;
};

class Animation
{
public:
    Animation();
    ~Animation();
    AnimationFrame *next(AnimationFrame *current);
private:
    std::vector<AnimationFrame*> *frames;
};

class Sprite 
{
public:
    Sprite();
    ~Sprite();
    void update(int delta);
    void render(SDL_Renderer *renderer, SDL_Texture *spritesheet);
private:
    void setFrame(AnimationFrame *a);
    int timer;
    Animation *animation;
    AnimationFrame *current;
    SDL_Rect *srect;
    SDL_Rect drect;
};