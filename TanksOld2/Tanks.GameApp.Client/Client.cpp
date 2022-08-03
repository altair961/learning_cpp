#include "Game.h"

Game* game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running()) //game loop while game is running
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();
		// handle any input
		// update all object eg. positions, etc
		// render changes to the display

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}