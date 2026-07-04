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
	mBallPos = 
	{ 
		static_cast <float>(1024 / 2 - thickness / 2), 
		static_cast <float>(768 / 2 - thickness / 2)
	};
	mPaddlePos = { static_cast<float>(thickness) / 2 + thickness, 768 / 2 };

	mTicksCount = 0;
	mPaddleDir = 0;
}
void Game::ProcessInput() 
{
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

	mPaddleDir = 0;
	if (state[SDL_SCANCODE_W]) 
	{
		mPaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}
}
void Game::UpdateGame() {
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;

	// Delta time is the difference in ticks from last frame
	// Converted to seconds
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f; // deltTime is in seconds
	
	// Update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();	

	// Clamp maximum delta time value
	if (deltaTime > 0.05f) 
	{
		deltaTime = 0.5f;
	}

	if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
		// make sure paddle doesn't go off screen
		if (mPaddlePos.y < (paddleH / 2.0f + thickness))
			mPaddlePos.y = paddleH / 2.0f + thickness;
		else if (mPaddlePos.y > (768.0f - paddleH / 2.0f - thickness))
		{
			mPaddlePos.y = (768.0f - paddleH / 2.0f - thickness);
		}
	}

	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;

	// Did the ball collide with the top wall?
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
	{
		mBallVel.y *= -1;
	}

	// Did the ball collide with the bottom wall?
	if (mBallPos.y + 2 * thickness >= 768 && mBallVel.y > 0.0f)
	{
		mBallVel.y *= -1;
	}

	// Did the ball collide with the right wall?
	if (mBallPos.x >= (1024 - thickness * 2) && mBallVel.x > 0.0f)
	{
		mBallVel.x *= -1;
	}

	// Did the ball intersect with the paddle?
	if (
		mBallPos.y + thickness > (mPaddlePos.y - (paddleH / 2))
		&& mBallPos.y < (mPaddlePos.y + (paddleH / 2))
		&&
		// Ball is at the correct x-position
		mBallPos.x <= (mPaddlePos.x + thickness) && mBallPos.x >= mPaddlePos.x &&
		// the ball is moving to the left
		mBallVel.x < 0.0f)
	{
		mBallVel.x *= -1;
	}

	if (BallComesFromTop() &&
		BallIsHigherThanPaddle() &&
		BallBottomHitPaddleTopAlready() &&
		BallIsAlignedWithPaddleXAxis())
	{
		mBallVel.y *= -1;
	}

	if (!BallComesFromTop() &&
		!BallIsHigherThanPaddle() &&
		BallTopHitPaddleBottomAlready() &&
		BallIsAlignedWithPaddleXAxis())
	{
		mBallVel.y *= -1;
	}

	if (BallMovedOffScreen()) 
	{
		GameOver();
	}
}

bool Game::BallMovedOffScreen()
{
	auto ballLeftSideX = mBallPos.x;
	auto ballRightSideX = ballLeftSideX + thickness;
	auto isBallOffScreenOnTheRightSide = ballLeftSideX > 1024;
	auto isBallOffScreenOnTheLeftSide = ballRightSideX < 0;
	auto result = isBallOffScreenOnTheRightSide	|| isBallOffScreenOnTheLeftSide;

	return result;
}

void Game::GameOver()
{
	mIsRunning = false;
}

bool Game::BallIsAlignedWithPaddleXAxis() 
{
	auto paddleRightSideX = mPaddlePos.x + thickness / 2;
	auto paddleLeftSideX = mPaddlePos.x - thickness / 2;
	auto ballLeftSideX = mBallPos.x - thickness / 2;
	auto ballRightSideX = mBallPos.x + thickness / 2;

	if (ballLeftSideX > paddleRightSideX)
		return false;

	if (ballRightSideX < ballLeftSideX)
		return false;

	if (ballLeftSideX <= paddleRightSideX && 
		ballLeftSideX >= paddleLeftSideX)
		return true;

	if (ballRightSideX <= paddleRightSideX &&
		ballRightSideX >= paddleLeftSideX)
		return true;

	return false;
}

bool Game::BallTopHitPaddleBottomAlready() 
{
	auto ballTopSideY = mBallPos.y;
	auto paddleBottomSideY = mPaddlePos.y + paddleH / 2;
	auto result = ballTopSideY <= paddleBottomSideY;

	return result;
}

bool Game::BallBottomHitPaddleTopAlready()
{
	auto ballBottomSideY = mBallPos.y + thickness;
	auto paddleTopSideY = mPaddlePos.y - paddleH / 2;
	auto result = ballBottomSideY >= paddleTopSideY;

	return result;
}

bool Game::BallIsHigherThanPaddle() 
{
	auto result = mBallPos.y < mPaddlePos.y;
	
	return result;
}

bool Game::BallComesFromTop() 
{
	auto result = mBallVel.y > 0.0f;

	return result;
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

	//SDL_SetRenderDrawColor(mRenderer, 255, 100, 255, 255);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_Rect ball{
		mBallPos.x,
		mBallPos.y,
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	SDL_Rect rightWall{ 1024 - thickness, 0, thickness, 768 };
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &rightWall);

	SDL_Rect paddle1{
		static_cast<int>(mPaddlePos.x),
		mPaddlePos.y - paddleH / 2,
		thickness,
		paddleH
	};
	SDL_RenderFillRect(mRenderer, &paddle1);

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