#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Tank.h"
#include <stdexcept>

using namespace std;

// Override base class with your custom functionality
class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		// Name your application
		sAppName = "Tanks";
	}

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		PTank.reset();
		PTank = make_shared<Tank>("Player's tank");

		spritePtr = make_unique<olc::Sprite>("./player's_tank_sprite_sheet.png");
		decalPtr = make_unique<olc::Decal>(spritePtr.get());
		currentTile = 0;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::DARK_BLUE);
		SetPixelMode(olc::Pixel::MASK); // Dont draw pixels which have any transparency

		olc::vf2d size = { 16, 16 };
		olc::vf2d sourceSize = { 16, 16 };
		
		
		DrawPartialDecal(position, size, decalPtr.get(), getSourcePos(currentTile, fElapsedTime), sourceSize);
		
		currentTile = GetNextTileIndex(currentTile, fElapsedTime);

		SetPixelMode(olc::Pixel::NORMAL); // Draw all pixels
		return true;
	}

private:
	unique_ptr<olc::Sprite> sprTile;
	shared_ptr<Tank> PTank;
	unique_ptr<olc::Sprite> spritePtr;
	unique_ptr<olc::Decal> decalPtr;
	olc::vf2d position{ 50, 69 };
	int currentTile;
	float currentTime = 0.0f;
	float mInterval = 0.005066;


	olc::vf2d getSourcePos(int currentTile, float fElapsedTime)
	{
		if (currentTile == 0)
			return olc::vf2d{ 0, 0 };

		if (currentTile == 1)
			return olc::vf2d{ 16, 0 };
	}

	int GetNextTileIndex(int currentTile, float fElapsedTime)
	{
		int tilesTotal = 2;
		int maxIndexValue = tilesTotal - 1;

		if (currentTile > maxIndexValue)
			throw invalid_argument("Current tile index cannot be greater than maximum index");

		currentTime += fElapsedTime;
		if (currentTime >= mInterval)
		{
			currentTime = 0.0f;
	
			if (currentTile < maxIndexValue) 
			{
				currentTile++;
				return currentTile;
			}

		}
		if (currentTile == maxIndexValue)
		{
			currentTile = 0;
			return currentTile;
		}

		return currentTile;
	}
};

int main()
{
	Game game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}