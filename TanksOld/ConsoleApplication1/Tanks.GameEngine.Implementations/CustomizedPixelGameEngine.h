#pragma once

#include "olcPixelGameEngine.h"

class CustomizedPixelGameEngine : public olc::PixelGameEngine
{
public:
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
};