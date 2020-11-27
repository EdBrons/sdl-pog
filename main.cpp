#include "game.hpp"

Game *game = nullptr;
const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("Game", 800, 600);
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}