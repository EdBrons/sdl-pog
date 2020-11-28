#include "sprite.hpp"

Animation::Animation()
{
    frames = new std::vector<AnimationFrame*>();
}

Animation::~Animation()
{
    free(frames);
}

AnimationFrame *Animation::next(AnimationFrame *current)
{
    bool next = false;
    for (auto f : *frames)
    {
        if (f == current)
        {
            next = true;
        }
        else if (next)
        {
            return f;
        }
    }
    return *frames->begin();
}

Sprite::Sprite()
{
    animation = nullptr;
    current = nullptr;
    srect = nullptr;
    drect = SDL_Rect { 0, 0, 16, 16 };
    int timer = 0;
}

Sprite::~Sprite()
{}

void Sprite::update(int delta)
{
    timer += delta;
    if (timer > current->duration)
    {
        timer = 0;
        setFrame(animation->next(current));
    }
}

void Sprite::setFrame(AnimationFrame *a)
{
    srect = &a->srect;
}

void Sprite::render(SDL_Renderer *renderer, SDL_Texture *spritesheet)
{
    SDL_RenderCopy(renderer, spritesheet, srect, &drect);
}