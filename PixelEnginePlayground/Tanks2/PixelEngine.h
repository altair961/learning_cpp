#pragma once
#include "olcPixelGameEngine.h"

class PixelEngine : public olc::PixelGameEngine
{
public:
	void DrawEntity();
	PixelEngine();
	~PixelEngine();
private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};
