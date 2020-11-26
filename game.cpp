#include "game.hpp"

SDL_Texture *playerTexture;
SDL_Rect srcR, destR;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int x, int y, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        isRunning = true;
    } else {
        std::cout << "SDL failed to inialize. SDL Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    SDL_Surface *tempSurface = IMG_Load("assets/Pixel_Art_Chess_DevilsWorkshop_V03/chess/black_king.png");
    playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
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
{
    destR.h = 100;
    destR.w = 100;
    destR.x++;
    destR.y = 0;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}