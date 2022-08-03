#include "PixelEngine.h"

PixelEngine::PixelEngine(std::shared_ptr<Game> pGameParam) : pGame(pGameParam)
{
	std::cout << "PixelEngine was constructed. " << std::endl;
}

PixelEngine::~PixelEngine()
{
	std::cout << "PixelEngine was destructed. " << std::endl;
}

void PixelEngine::Initialize(int screenWidth, int screenHeight, int pixelWidth, 
	int pixelHeight, bool enableFullScr, bool enableVSync)
{
	bool isSuccessful = false;
	isSuccessful = Construct(screenWidth, screenHeight, pixelWidth, 
		pixelHeight, enableFullScr, enableVSync);
	
	if (isSuccessful == true)
		SetIsInitialized(true);
}

void PixelEngine::SetIsInitialized(bool isInitializedValue)
{
	IsInitialized = isInitializedValue;
}

bool PixelEngine::GetIsInitialized() 
{
	return IsInitialized;
}

void PixelEngine::Launch() 
{
	if(!GetIsInitialized())
	{
		InitializeWithDefaults();
	}

	Start();
}

void PixelEngine::InitializeWithDefaults() 
{
	Construct(256, 240, 4, 4, false, false);
}

bool PixelEngine::OnUserCreate()
{
	return true;
}

bool PixelEngine::OnUserUpdate(float fElapsedTime)
{
	// Called once per frame, draws random coloured pixels
	//for (int x = 0; x < ScreenWidth(); x++)
	//	for (int y = 0; y < ScreenHeight(); y++)
	//		Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

	// process user inputs
	// updates game state
	pGame->PTank->Move();// Move updates Map (map has no walls)
	// renders
	//ask Map about tank position and draw it

	return true;
}