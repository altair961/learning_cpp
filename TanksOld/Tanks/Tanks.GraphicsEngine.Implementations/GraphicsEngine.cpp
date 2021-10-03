#include "GraphicsEngine.h"
/*
void GraphicsEngine::ConstructEngine(int scrWidth, int scrHeight, int pxWidth, int pxHeight, olc::PixelGameEngine e)
{
	GraphicsEngineInstance = std::make_shared<olc::PixelGameEngine>();
	GraphicsEngineInstance->e.Construct(scrWidth, scrHeight, pxWidth, pxHeight);
}

//void GraphicsEngine::StartEngine() 
//{
//	GraphicsEngineInstance->Start();
//}

bool GraphicsEngine::OnUserUpdate(float fElapsedTime)
{
	// called once per frame, draws random coloured pixels
	for (int x = 0; x < ScreenWidth(); x++)
		for (int y = 0; y < ScreenHeight(); y++)
			Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

}*/

void GraphicsEngine::StartEngine()
{
}

void GraphicsEngine::OnUpdateScene()
{
}
