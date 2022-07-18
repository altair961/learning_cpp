#include "olcPixelGameEngine.h"
#pragma once
class RenderEngine : olc::PixelGameEngine
{
public:
	RenderEngine(std::string windowTitle);
	bool OnUserUpdate(float fElapsedTime) override;
	olc::rcode Construct1(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync, bool cohesion);
	olc::rcode Start1();
};