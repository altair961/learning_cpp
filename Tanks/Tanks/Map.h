#pragma once
#include <memory>
#include <vector>
#include "Tank.h"

class Map 
{
public:
	void AddTank(std::shared_ptr<Tank> pTankParam);
	std::vector<std::shared_ptr<Tank>> Tanks;
};