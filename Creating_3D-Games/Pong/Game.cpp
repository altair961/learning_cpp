#include "Game.h"

void Game::RunLoop()
{
	while (mIsRunning)
	{
		// Process Inputs
		ProcessInput();
		// Update Game World
		UpdateGame();
		// Generate Outputs
		GenerateOutput();
	}
}
Game::Game() {
	mWindow = nullptr;
	mIsRunning = true;
	mBallPos = { 1024 / 2, 768 / 2 };
	mPaddlePos = { static_cast<float>(thickness) / 2 + thickness, 768 / 2 };
}
void Game::ProcessInput() {
	SDL_Event event;
	// While there are still events in the queue
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	// Get the state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// if escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
}
void Game::UpdateGame() {
}
void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(mRenderer, 57, 83, 164, 255);
	SDL_RenderClear(mRenderer);

	SDL_Rect topWall{ 0, 0, 1024, thickness };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &topWall);

	SDL_Rect bottomWall{ 0, 768 - thickness, 1024, thickness };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &bottomWall);

	SDL_Rect rightWall{ 1024 - thickness, 0, thickness, 768 };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &rightWall);

	SDL_Rect ball{
		static_cast<int>(mBallPos.x - thickness / 2),
		static_cast<int>(mBallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);

	SDL_Rect paddle{
		static_cast<int>(mPaddlePos.x - thickness / 2),
		mPaddlePos.y - (thickness * 6.5) / 2,
		thickness,
		thickness * 6.5
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	SDL_RenderPresent(mRenderer);
}
bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) 
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chapter 1)", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);
	if (!mWindow) 
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	
	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
}
void Game::Shutdown() {
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}