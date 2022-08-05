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
	std::unique_ptr<olc::Sprite>pSprite;
	std::unique_ptr<olc::Decal>pDecal;
	int GetNextTileIndex(int currentTile, float fElapsedTime);
	int currentTile;
	olc::vf2d getSourcePos(int currentTile, float fElapsedTime);
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