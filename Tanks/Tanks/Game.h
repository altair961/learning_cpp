#pragma once
#include "Tank.h"
#include <memory>

class Game 
{
public:
	std::shared_ptr<Tank> PTank;
	Game();
	~Game();
};