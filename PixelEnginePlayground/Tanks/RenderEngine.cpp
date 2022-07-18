#include "RenderEngine.h"
#pragma once

RenderEngine::RenderEngine(std::string windowTitle)
{
}

bool RenderEngine::OnUserUpdate(float fElapsedTime)
{
	// Called once per frame, draws random coloured pixels
	
	for (int x = 0; x < ScreenWidth(); x++)
		for (int y = 0; y < ScreenHeight(); y++)
			Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
	
	return true;
}

olc::rcode RenderEngine::Construct1(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, 
	bool full_screen, bool vsync, bool cohesion)
{
	return Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen, vsync, cohesion);
}

olc::rcode RenderEngine::Start1()
{
	return Start();
}