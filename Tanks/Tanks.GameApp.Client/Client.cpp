#include "Game.h"

Game* game = nullptr;

int main(int argc, char *argv[])
{
	game = new Game();
	game->init("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running()) //game loop while game is running
	{
		game->handleEvents();
		game->update();
		game->render();
		// handle any input
		// update all object eg. positions, etc
		// render changes to the display
	}

	game->clean();

	return 0;
}