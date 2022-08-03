#pragma once
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

using namespace olc;

class PixelEngine : public olc::PixelGameEngine
{
public:
	void DrawEntity(int someEntityLikeTank) 
	{
		// we draw it on the screen using pge infrastructure
	}

	PixelEngine()
	{
		// Name your application
//		sAppName = "Example";
	}

	bool OnUserCreate() //override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) //override
	{
		// Called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

		return true;
	}
};
