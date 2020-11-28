#include "sprite.hpp"

Sprite::Sprite()
{
    srect = nullptr;
    drect = nullptr;
    loop = nullptr;
    animation_timer = 0;
}

Sprite::~Sprite()
{}

void Sprite::update(int delta)
{
    animation_timer += delta;
    if (animation_timer > ANIMATION_TIME)
    {
        animation_timer = 0;
        bool next = false;
        for (SDL_Rect *r : *loop) {
            if (r == srect)
            {
                next = true;
            } else if (next)
            {
                srect = r;
                return;
            }
        }
        srect = *loop->begin();
    }
}

void Sprite::render(SDL_Renderer *renderer, SDL_Texture *spritesheet)
{
    SDL_RenderCopy(renderer, spritesheet, srect, drect);
}

void Sprite::play_animation(std::vector<SDL_Rect*>* l)
{
    loop = l;
}