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

	SDL_Rect wall{ 0, 0, 1024, thickness };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &wall);

	SDL_Rect wall1{ 0, 768 - thickness, 1024, thickness };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &wall1);

	SDL_Rect wall2{ 0, 0, thickness, 768 };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &wall2);

	SDL_Rect wall3{ 1024 - thickness, 0, thickness, 768 };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &wall3);

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