#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		DrawPixel(0,0,4);
		// Called once per frame, draws random coloured pixels
		/*
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		*/
		return true;
	}

	void DrawPixel(int xPosition, int yPosition, int pixelSide)
	{
		FillRect(xPosition, yPosition, pixelSide, pixelSide);
		/*
		for (int i = 0; i < pixelSide; i++)
		{
			Draw(xPosition, yPosition, olc::Pixel(255, 255, 255));
		}

		Draw(xPosition, yPosition, olc::Pixel(255, 255, 255));
		Draw(xPosition, yPosition + pixelSide, olc::Pixel(255, 255, 255));
		Draw(xPosition + pixelSide, yPosition, olc::Pixel(255, 255, 255));
		Draw(xPosition + pixelSide, yPosition + pixelSide, olc::Pixel(255, 255, 255));
		*/
	}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}
