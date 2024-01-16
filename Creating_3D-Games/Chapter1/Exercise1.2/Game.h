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
	bool BallComesFromTop();
	bool BallBottomHitPaddleTopAlready(int paddlePositionY);
	bool BallTopHitPaddleBottomAlready(int paddlePositionY);
	bool BallIsHigherThanPaddle(int paddlePositionY);
	bool BallIsAlignedWithPaddleXAxis(int mPaddlePosX);
	bool BallMovedOffScreen();
	bool BallBottomIsLowerThanPaddleTop(int paddlePositionY);
	bool BallTopIsHigherThanPaddleBottom(int paddlePositionY);
	void GameOver();

	SDL_Window* mWindow;
	bool mIsRunning;
	SDL_Renderer* mRenderer;
	const int thickness = 15;
	struct Vector2 
	{
		float x;
		float y;
	};
	Vector2 mPaddle1Pos
	{
	};
	Vector2 mPaddle2Pos
	{
	};
	Vector2 mBallPos
	{
	};
	Uint32 mTicksCount;
	int mPaddle1Dir;
	int mPaddle2Dir;
	const int mPaddleH = thickness * 6.5;
	Vector2 mBallVel{ 200, 100};
	void HandleTopBottomCollisions(Game::Vector2 paddlePos);
};