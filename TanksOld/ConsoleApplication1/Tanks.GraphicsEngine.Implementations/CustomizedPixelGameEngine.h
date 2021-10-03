#pragma once

#include "olcPixelGameEngine.h"

class CustomizedPixelGameEngine : public olc::PixelGameEngine
{
public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};