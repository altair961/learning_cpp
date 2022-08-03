#include "PixelEngine.h"

PixelEngine::PixelEngine()
{
	std::cout << "PixelEngine object was contructed. " << std::endl;
}

PixelEngine::~PixelEngine()
{
	std::cout << "PixelEngine object was distructed. " << std::endl;
}

void PixelEngine::DrawEntity() 
{
}

bool PixelEngine::OnUserCreate()
{
	return true;
}

bool PixelEngine::OnUserUpdate(float fElapsedTime)
{
	//for (int x = 0; x < ScreenWidth(); x++)
	//	for (int y = 0; y < ScreenHeight(); y++)
	//		Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
	return true;

}
