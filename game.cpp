#include "game.hpp"

SDL_Renderer *Game::Renderer = nullptr;
SDL_Texture *Game::SpriteSheet = nullptr;

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

    // load spritesheet
    SpriteSheet = TextureManager::LoadTexture("assets/microFantasy.v0.4/characters/all.png");

    sprites = new std::vector<Sprite*>();

    Sprite *my_sprite = makeSprite();
}

Sprite *Game::makeSprite()
{
    Sprite *s = new Sprite();
    sprites->push_back(s);
    return s;
}

void Game::removeSprite(Sprite *sprite)
{
    for (auto el = sprites->begin(); el != sprites->end();)
    {
        if (*el == sprite)
        {
            sprites->erase(el);
            free(sprite);
        }
        else
        {
            ++el;
        }
    }
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
{}

void Game::render(int delta)
{
    SDL_RenderClear(Renderer);
    // render sprites
    for (auto s : *sprites)
    {
        s->update(delta);
        s->render(Renderer);
    }
    SDL_RenderPresent(Renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}