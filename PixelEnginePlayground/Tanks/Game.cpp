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

		//sprTile = std::make_unique<olc::Sprite>("./tank.png");

		spritePtr = std::make_unique<olc::Sprite>("./tank.png");
		decalPtr = std::make_unique<olc::Decal>(spritePtr.get());

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::DARK_BLUE);
		SetPixelMode(olc::Pixel::MASK); // Dont draw pixels which have any transparency

		// DrawSprite(olc::vi2d(16, 16), sprTile.get());
		// AnimationData animationData = spriteAnimation.GetInfo(fElapsedTime);
		olc::vf2d size = { 16, 16 };
		olc::vf2d sourceSize = { 16, 16 };
		
		DrawPartialDecal(position, size, decalPtr.get(), getSourcePos(), sourceSize);
	
		SetPixelMode(olc::Pixel::NORMAL); // Draw all pixels
		return true;
	}

private:
	std::unique_ptr<olc::Sprite> sprTile;
	std::shared_ptr<Tank> PTank;
	std::unique_ptr<olc::Sprite> spritePtr;
	std::unique_ptr<olc::Decal> decalPtr;
	olc::vf2d position{ 50, 69 };
	olc::vf2d getSourcePos()
	{
		int r = rand() % 256;

		olc::vf2d result;
		if (r > 35)
		{
			
			return olc::vf2d{ 0, 0 };
		}
		
		return olc::vf2d{ 16, 0 };
	}
};

int main()
{
	Game game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}