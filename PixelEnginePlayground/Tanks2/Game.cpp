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

		sprTile = std::make_unique<olc::Sprite>("./tank.png");

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::DARK_BLUE);

		auto v = PTank->PTankPicture;
		
//		olc::Sprite sprite("./tank.png");

		DrawSprite(olc::vi2d(5, 5), sprTile.get());

		/*	Sprite::Sprite(const std::string & sImageFile, olc::ResourcePack * pack)
		{
			LoadFromFile(sImageFile, pack);
		}*/
//		decal
	//	DrawPartialWarpedDecal();

		for (int i = 0; i <= 2; i++) 
		{
			Draw(PTank->PTankPicture->at(i).XPosition,
				PTank->PTankPicture->at(i).YPosition, olc::Pixel(
					PTank->PTankPicture->at(i).RColorChannel,
					PTank->PTankPicture->at(i).GColorChannel,
					PTank->PTankPicture->at(i).BColorChannel));
		}


		

		//for (int x = 0; x < ScreenWidth(); x++)
		//	for (int y = 0; y < ScreenHeight(); y++)
		//		Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		
		return true;
	}

private:
	std::unique_ptr<olc::Sprite> sprTile;
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