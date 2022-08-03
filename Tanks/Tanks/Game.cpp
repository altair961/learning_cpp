#include "Game.h"
#include <iostream>
#include <memory>

Game::Game()
{
	PTank.reset();
	PTank = std::make_shared<Tank>();

	std::cout << "Game was constructed. " << std::endl;
}

Game::~Game() 
{
	std::cout << "Game was destructed. " << std::endl;
}