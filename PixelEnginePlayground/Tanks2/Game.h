#pragma once
#include <memory>
#include "PixelEngine.h"

class Game 
{
private:
	std::unique_ptr<PixelEngine> pPixelEngine;
	int screenwidth = 256;
	int screenheight = 240;
	int pixelwidth = 4;
	int pixelheight = 4;

public:
	Game();
	~Game();
	void Launch();
};