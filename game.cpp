#include "game.hpp"

SDL_Renderer *Game::Renderer = nullptr;
Sprite *Game::sprite = nullptr;
SDL_Texture *Game::SpriteSheet = nullptr;
std::map<std::string, std::vector<SDL_Rect*>*> *Animations = nullptr;

// Sprite *sprite = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        Renderer = SDL_CreateRenderer(window, -1, 0);
        isRunning = true;
    } 
    else 
    {
        std::cout << "SDL failed to inialize. SDL Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    TextureManager::LoadSpriteSheet("assets/microFantasy.v0.4/characters/all.png", "assets/microFantasy.v0.4/characters/all.json");
    // SpriteSheet = TextureManager::LoadTexture("assets/microFantasy.v0.4/characters/all.png");
    // sprite = new Sprite();
    // sprite->play_animation(TextureManager::GetAnimation("barbarian_attack"));
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(int delta)
{
    // sprite->update(delta);
}

void Game::render()
{
    SDL_RenderClear(Renderer);
    // sprite->render();
    SDL_RenderPresent(Renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}