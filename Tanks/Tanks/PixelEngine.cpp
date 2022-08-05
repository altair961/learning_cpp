#include "PixelEngine.h"
#include <stdexcept>

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
	Construct(256, 240, 4, 4, false, true);
}

bool PixelEngine::OnUserCreate()
{
	pSprite.reset();
	pSprite = std::make_unique<olc::Sprite>(pGame->pTank->PathToSpriteSheet);
	
	pDecal.reset();
	pDecal = std::make_unique<olc::Decal>(pSprite.get());

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
	pGame->pTank->Move();// Move updates Map (map has no walls)
	// renders
	//ask Map about tank position and draw it

	// Called once per frame, draws random coloured pixels
	Clear(olc::DARK_BLUE);
	SetPixelMode(olc::Pixel::MASK); // Dont draw pixels which have any transparency

	olc::vf2d size = { 16, 16 };
	olc::vf2d sourceSize = { 16, 16 };
	olc::vf2d position{ 50, 69 };



	DrawPartialDecal(position, size, pDecal.get(), getSourcePos(currentTile, fElapsedTime), sourceSize);
	currentTile = GetNextTileIndex(currentTile, fElapsedTime);

	SetPixelMode(olc::Pixel::NORMAL); // Draw all pixels

	return true;
}

int PixelEngine::GetNextTileIndex(int currentTile, float fElapsedTime)
{
	int tilesTotal = 2;
	int maxIndexValue = tilesTotal - 1;

	if (currentTile > maxIndexValue)
		throw std::invalid_argument("Current tile index cannot be greater than maximum index");

	/*currentTime += fElapsedTime;
	if (currentTime >= mInterval)
	{
		currentTime = 0.0f;
*/
	if (currentTile < maxIndexValue)
	{
		currentTile++;
		return currentTile;
	}

	//}
	if (currentTile == maxIndexValue)
	{
		currentTile = 0;
		return currentTile;
	}

	return currentTile;
}

olc::vf2d PixelEngine::getSourcePos(int currentTile, float fElapsedTime)
{
	if (currentTile == 0)
		return olc::vf2d{ 0, 0 };

	if (currentTile == 1)
		return olc::vf2d{ 16, 0 };
}