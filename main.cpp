#include "game.hpp"

Game *game = nullptr;
const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int argc, char* args[])
{
	game = new Game();
	game->init("Game", 800, 600);
	Uint32 lastupdate = SDL_GetTicks();
	while (game->running())
	{
		Uint32 now = SDL_GetTicks();
		int delta = now - lastupdate;
		if (delta > frameDelay)
		{
			game->handleEvents();
			game->update();
			lastupdate = now;
		}
		game->render(delta);
	}
	game->clean();
	return 0;
}