#pragma once
#include <SDL.h>

class Game {
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	bool mIsRunning;
	SDL_Renderer* mRenderer;
	const int thickness = 15;
	struct Vector2 
	{
		float x;
		float y;
	};
	Vector2 mPaddlePos
	{
	};
	Vector2 mBallPos
	{
	};
};