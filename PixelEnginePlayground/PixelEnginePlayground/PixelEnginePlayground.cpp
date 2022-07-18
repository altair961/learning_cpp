#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Tank.h"

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
	Tank PlayerTank;
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		PlayerTank = Tank(0, 0);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		PlayerTank.Draw();
		//DrawPixel(0,0,4);
		//DrawTank(0, 0);
		// Called once per frame, draws random coloured pixels
		/*
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		*/
		return true;
	}
	bool OnUserDestroy() {
		
	}

private:

	void DrawPixel(int xPosition, int yPosition, int pixelSide)
	{
		FillRect(xPosition, yPosition, pixelSide, pixelSide);
	}

	//void DrawObject(IDrawable drawable)
	//{

	//}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}

