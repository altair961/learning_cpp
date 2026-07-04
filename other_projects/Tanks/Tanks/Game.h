#pragma once
#include "Tank.h"
#include <memory>

class Game 
{
public:
	std::unique_ptr<Tank> pTank;
	Game();
	~Game();
};