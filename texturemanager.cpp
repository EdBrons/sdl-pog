#include "game.hpp"
#include "texturemanager.hpp"

nlohmann::json;

SDL_Texture *TextureManager::LoadTexture(const char *file)
{
    SDL_Surface *tempSurface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

// std::vector<SDL_Rect*> *TextureManager::GetAnimation(std::string name)
// {
//     return TextureMap->find(name)->second;
// }

AnimationFrame *TextureManager::LoadAnimation(const char *name, const char *json)
{
    int id = 0;
    std::ifstream ifs(json);
    nlohmann::json j = nlohmann::json::parse(ifs);
    AnimationFrame **head = nullptr;
    AnimationFrame *current;
    head = &current;
    auto a = j.find(name);
    nlohmann::json frames = (*a)["frames"];
    for (auto b = frames.begin(); b != frames.end(); ++b)
    {
        current = new AnimationFrame();
        current->id = id;
        id++;
        int x = (*b)["x"];
        int y = (*b)["y"];
        int w = (*b)["w"];
        int h = (*b)["h"];
        int t = (*b)["duration"];
        SDL_Rect *rect = new SDL_Rect();
        rect->x = x;
        rect->y = y;
        rect->w = w;
        rect->h = h;
        current->srect = rect;
        current->time = t;
    }
    return *head;
}