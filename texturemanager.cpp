#include "texturemanager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *file, SDL_Renderer *renderer)
{
    SDL_Surface *tempSurface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}