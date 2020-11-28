#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>

class Sprite 
{
public:
    Sprite();
    ~Sprite();
    void update(int delta);
    void render(SDL_Renderer *renderer);
private:
};
#endif