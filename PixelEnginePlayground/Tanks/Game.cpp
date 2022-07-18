#include "Game.h"
#include <memory>
#include "RenderEngine.h"

Game::Game(std::shared_ptr<RenderEngine> pRenderEng) : PRenderEng (pRenderEng)
{
}

void Game::Launch()
{
	if (PRenderEng->Construct1(256, 240, 4, 4, false, false, false))
		PRenderEng->Start1();

	// start window
	// create Tank
	// ask window to show the tank
}
