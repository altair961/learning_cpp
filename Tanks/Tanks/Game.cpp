#include "Game.h"
#include <iostream>
#include <memory>

Game::Game()
{
	pTank.reset();
	pTank = std::make_unique<Tank>();

	std::cout << "Game was constructed. " << std::endl;
}

Game::~Game() 
{
	std::cout << "Game was destructed. " << std::endl;
}