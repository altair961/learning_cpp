#pragma once
#include "olcPixelGameEngine.h"
#include "Game.h"
#include <memory>

class PixelEngine : public olc::PixelGameEngine
{
private:
	bool IsInitialized = false;
	void SetIsInitialized(bool isInitializedValue);
	std::shared_ptr<Game> pGame;
public:
	bool GetIsInitialized();
	void Initialize(int screenWidth, int screenHeight, int pixelWidth, 
		int pixelHeight, bool enableFullScr, bool enableVSync);
	void Launch();
	PixelEngine(std::shared_ptr<Game> pGame);
	~PixelEngine();
	void InitializeWithDefaults();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};