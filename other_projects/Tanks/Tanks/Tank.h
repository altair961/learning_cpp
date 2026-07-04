#pragma once
#include <memory>
#include "olcPixelGameEngine.h"
#include <string>

class Tank
{
public:
	std::string PathToSpriteSheet;
	Tank();
	~Tank();
	void Move();
};