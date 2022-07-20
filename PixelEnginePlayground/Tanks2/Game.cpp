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
		sAppName = "Game";
	}

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		PTank.reset();
		PTank = std::make_shared<Tank>("123");
		PTank->AddResource();
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::DARK_BLUE);

		

		Draw(PTank->PTankPicture->at(0).XPosition, 
			PTank->PTankPicture->at(0).YPosition, olc::Pixel(
				PTank->PTankPicture->at(0).RColorChannel, 
				PTank->PTankPicture->at(0).GColorChannel, 
				PTank->PTankPicture->at(0).BColorChannel));

		//for (int x = 0; x < ScreenWidth(); x++)
		//	for (int y = 0; y < ScreenHeight(); y++)
		//		Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		
		return true;
	}

private:
	std::shared_ptr<Tank> PTank;
	void DrawPixel(int xPosition, int yPosition, int pixelSide)
	{
		FillRect(xPosition, yPosition, pixelSide, pixelSide);
	}
};

int main()
{
	Game game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}