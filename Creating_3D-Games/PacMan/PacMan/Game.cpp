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
}
void Game::UpdateGame() {
}
void Game::GenerateOutput() {
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
}
void Game::Shutdown() {
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}