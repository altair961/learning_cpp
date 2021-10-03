#pragma once
#include "TanksGraphicsEngineInterfaces.h" 
#include "olcPixelGameEngine.h"

class GraphicsEngine : IGraphicsEngine
{
public:
	virtual void StartEngine();
	virtual void OnUpdateScene();
};
