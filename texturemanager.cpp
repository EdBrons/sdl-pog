#include "game.hpp"
#include "texturemanager.hpp"

using json = nlohmann::json;

std::map<std::string, std::vector<SDL_Rect*>*> *TextureManager::TextureMap = nullptr;

SDL_Texture *TextureManager::LoadTexture(const char *file)
{
    SDL_Surface *tempSurface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

std::vector<SDL_Rect*> *TextureManager::GetAnimation(std::string name)
{
    if (!TextureMap) 
    {
        std::cout << "NANI?" << std::endl;
    }
    // return TextureMap->find(name)->second;
    // auto a = TextureMap->find(name);
    // if (a == TextureMap->end())
    // {
        // std::cout << "Error!" << std::endl;
    // }
    return nullptr;
}

std::map<std::string, std::vector<SDL_Rect*>*> *TextureManager::LoadSpriteSheet(const char *file, const char *jsonfile)
{
    // TextureMap = new std::map<std::string, std::vector<SDL_Rect*>*>();
    // std::ifstream ifs(jsonfile);
    // json j = json::parse(ifs);

    // for (auto a = j.begin(); a != j.end(); ++a)
    // {
        // std::string name = a.key();
        // std::vector<SDL_Rect*> *frames_vector = new std::vector<SDL_Rect*>();
        // json frames = (*a)["frames"];
        // for (auto b = frames.begin(); b != frames.end(); ++b)
        // {
            // int x = (*b)["x"];
            // int y = (*b)["y"];
            // int w = (*b)["w"];
            // int h = (*b)["h"];
            // SDL_Rect *rect = new SDL_Rect();
            // rect->x = x;
            // rect->y = y;
            // rect->w = w;
            // rect->h = h;
            // frames_vector->push_back(rect);
        // }
        // TextureMap->insert(std::make_pair(name, frames_vector));
    // }
}