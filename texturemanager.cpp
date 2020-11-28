#include "texturemanager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *file)
{
    SDL_Surface *tempSurface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

// std::vector<AnimationFrame> *TextureManager::LoadAnimation(const char *name, const char *json)
// {
    // std::ifstream ifs(json);
    // std::vector<AnimationFrame> *frames_vector = new std::vector<AnimationFrame>();
    // auto anim = nlohmann::json::parse(ifs)[name];
    // auto frames = anim["frames"];
    // for (auto b = frames.begin(); b != frames.end(); ++b)
    // {
    //     id++;
    //     int x = (*b)["x"];
    //     int y = (*b)["y"];
    //     int w = (*b)["w"];
    //     int h = (*b)["h"];
    //     int t = (*b)["duration"];
    //     SDL_Rect *rect = new SDL_Rect();
    //     rect->x = x;
    //     rect->y = y;
    //     rect->w = w;
    //     rect->h = h;
    //     current->srect = rect;
    // }
    // return nullptr;
// }