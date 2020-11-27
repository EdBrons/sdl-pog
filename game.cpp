#include "game.hpp"
#include "texturemanager.hpp"

SDL_Renderer *Game::Renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int width, int height)
{
    int flags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        Renderer = SDL_CreateRenderer(window, -1, 0);
        _running = true;
    } else 
    {
        std::cout << "SDL failed to inialize. SDL Error: " << SDL_GetError() << std::endl;
        _running = false;
    }
}

void Game::handleEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{}

void Game::render()
{
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}