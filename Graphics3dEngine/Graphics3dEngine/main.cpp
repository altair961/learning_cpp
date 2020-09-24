#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Graphics3dEngine : public olc::PixelGameEngine
{
public:
	Graphics3dEngine()
	{
		sAppName = "Graphics3dEngine";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		return true;
	}
};

int main()
{
	Graphics3dEngine graphics3dEngine;
	if (graphics3dEngine.Construct(256, 240, 4, 4))
		graphics3dEngine.Start();

	return 0;
}