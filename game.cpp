#include "game.hpp"

SDL_Renderer *Game::Renderer = nullptr;
SDL_Texture *Game::SpriteSheet = nullptr;
AnimationFrame *Game::BarbarianAttack = nullptr;
AnimationFrame *Game::currentFrame = nullptr;
SDL_Rect Game::drect;
int Game::timer = 0;

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
    SpriteSheet = TextureManager::LoadTexture("assets/microFantasy.v0.4/characters/all.png");
    BarbarianAttack = TextureManager::LoadAnimation("barbarian_attack", "assets/microFantasy.v0.4/characters/all.json");
    std::cout << BarbarianAttack->id << std::endl;
    currentFrame = BarbarianAttack;
    drect.x = 0;
    drect.y = 0;
    drect.w = 100;
    drect.h = 100;
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

void Game::update()
{
    timer++;
    if (timer > currentFrame->time)
    {
        timer = 0;
        currentFrame = currentFrame->next;
    }
}

void Game::render()
{
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, SpriteSheet, currentFrame->srect, &drect);
    SDL_RenderPresent(Renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}