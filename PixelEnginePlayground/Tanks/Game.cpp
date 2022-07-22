#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Tank.h"

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
		PTank = std::make_shared<Tank>("Player's tank");

		sprTile = std::make_unique<olc::Sprite>("./tank.png");
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::DARK_BLUE);
		SetPixelMode(olc::Pixel::MASK); // Dont draw pixels which have any transparency

		DrawSprite(olc::vi2d(16, 16), sprTile.get());
	
		SetPixelMode(olc::Pixel::NORMAL); // Draw all pixels
		return true;
	}

private:
	std::unique_ptr<olc::Sprite> sprTile;
	std::shared_ptr<Tank> PTank;
};

int main()
{
	Game game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}