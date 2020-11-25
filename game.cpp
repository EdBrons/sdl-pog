#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "game.hpp"

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
        std::cout << "SDL initialized." << std::endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window)
        {
            std::cout << "Window created." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created." << std::endl;
        }

        isRunning = true;
    } else {
        std::cout << "SDL failed to inialize. SDL Error: " << SDL_GetError() << std::endl;
        isRunning = false;
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
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}