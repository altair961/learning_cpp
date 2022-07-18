#pragma once
#include "RenderEngine.h"
#include "Tank.h"

class Game 
{
public:
	Game(std::shared_ptr<RenderEngine> pRenderEng);

	void Launch();
private:
	std::shared_ptr<RenderEngine> PRenderEng;
};