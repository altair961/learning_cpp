#include "Game.h"
#include <iostream>

Game::Game() 
{
	pPixelEngine = std::make_unique<PixelEngine>();
	pPixelEngine->Construct(screenwidth, screenheight, pixelwidth, pixelheight);
	std::cout << "Game object was contructed. " << std::endl;
}

Game::~Game() 
{
	std::cout << "Game object was distructed. " << std::endl;
}

void Game::Launch()
{
	pPixelEngine->Start();
}