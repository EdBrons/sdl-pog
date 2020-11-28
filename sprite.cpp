#include "sprite.hpp"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::update(int delta)
{

}

void Sprite::render(SDL_Renderer *renderer, SDL_Texture *spritesheet)
{
    SDL_RenderCopy(renderer, spritesheet, srect, &drect);
}