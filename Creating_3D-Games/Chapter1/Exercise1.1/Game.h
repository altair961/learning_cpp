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
	bool BallBottomHitPaddleTopAlready();
	bool BallTopHitPaddleBottomAlready();
	bool BallIsHigherThanPaddle();
	bool BallIsAlignedWithPaddleXAxis();
	bool BallMovedOffScreen();
	bool BallBottomIsLowerThanPaddleTop();
	bool BallTopIsHigherThanPaddleBottom();
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
	//Vector2 mBallVel{ 100, 0 };
	Vector2 mBallVel{ 0, 0};
	//Vector2 mBallVel{ -200, -100 };
	//Vector2 mBallVel{ 2, 1 };
	//Vector2 mBallVel{ -100, 0 };
	//Vector2 mBallVel{ 0, -40 };
};