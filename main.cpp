#include <SDL2/SDL.h>
#include "game.hpp"

Game *game = nullptr;

int main(int argc, char* args[])
{
	game = new Game();
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
}