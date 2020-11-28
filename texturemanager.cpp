#include "texturemanager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *file)
{
    SDL_Surface *tempSurface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

static std::vector<AnimationFrame*> *LoadAnimation(const char *name, const char *json)
{
    std::ifstream ifs(json);
    auto anim = nlohmann::json::parse(ifs)[name];
    std::vector<AnimationFrame*> *frames_vector = new std::vector<AnimationFrame*>();
    auto frames = anim["frames"];
    for (auto b = frames.begin(); b != frames.end(); ++b)
    {
        AnimationFrame *a = new AnimationFrame();
        int x = (*b)["x"];
        int y = (*b)["y"];
        int w = (*b)["w"];
        int h = (*b)["h"];
        int d = (*b)["duration"];
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        a->srect = rect;
        a->duration = d;
        frames_vector->push_back(a);
    }
    return frames_vector;
}