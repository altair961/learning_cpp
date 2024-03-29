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
	mPaddle1Pos = { 
		0 + static_cast<float>(thickness) / 2 + thickness, 
		static_cast <float>(768 / 2) - mPaddleH / 2
	};
	mPaddle2Pos = { 
		1024 - static_cast<float>(thickness) / 2 - thickness - thickness, 
		(static_cast<float>(768 / 2)) - (mPaddleH / 2)
	};
	mTicksCount = 0;
	mPaddle1Dir = 0;
	mPaddle2Dir = 0;
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

	mPaddle1Dir = 0;
	if (state[SDL_SCANCODE_W]) 
	{
		mPaddle1Dir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddle1Dir += 1;
	}
	
	mPaddle2Dir = 0;
	if (state[SDL_SCANCODE_I])
	{
		mPaddle2Dir -= 1;
	}
	if (state[SDL_SCANCODE_K])
	{
		mPaddle2Dir += 1;
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

	if (mPaddle1Dir != 0)
	{
		mPaddle1Pos.y += mPaddle1Dir * 300.0f * deltaTime;
		// make sure player 1 paddle doesn't go off screen
		if (mPaddle1Pos.y < thickness)
			mPaddle1Pos.y = thickness;
		else if (mPaddle1Pos.y > (768.0f - mPaddleH - thickness))
		{
			mPaddle1Pos.y = (768.0f - mPaddleH - thickness);
		}
	}

	if (mPaddle2Dir != 0)
	{
		mPaddle2Pos.y += mPaddle2Dir * 300.0f * deltaTime;
		// make sure player 2 paddle doesn't go off screen
		if (mPaddle2Pos.y < thickness)
			mPaddle2Pos.y = thickness;
		else if (mPaddle2Pos.y > (768.0f - mPaddleH - thickness))
		{
			mPaddle2Pos.y = (768.0f - mPaddleH - thickness);
		}
	}

	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;

	// Did the ball collide with the top wall?
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
		mBallVel.y *= -1;	

	// Did the ball collide with the bottom wall?
	if (mBallPos.y + 2 * thickness >= 768 && mBallVel.y > 0.0f)
		mBallVel.y *= -1;

	// Did the ball intersect with the player 1 paddle (the left side)?
	if (BallBottomIsLowerThanPaddleTop(mPaddle1Pos.y)
		&& BallTopIsHigherThanPaddleBottom(mPaddle1Pos.y)
		// Ball at the correct x-position
		&& mBallPos.x <= (mPaddle1Pos.x + thickness) && mBallPos.x >= mPaddle1Pos.x
		// the ball is moving from the right
		&& mBallVel.x < 0.0f)
			mBallVel.x *= -1;

	// Did the ball intersect with the player 2 paddle (the right side)?
	if (BallBottomIsLowerThanPaddleTop(mPaddle2Pos.y)
		&& BallTopIsHigherThanPaddleBottom(mPaddle2Pos.y)
		// Ball at the correct x-position
		&& (mBallPos.x + thickness) >= (mPaddle2Pos.x) && (mBallPos.x + thickness) <= mPaddle2Pos.x + thickness
		// the ball is moving from the left
		&& mBallVel.x > 0.0f)
			mBallVel.x *= -1;

	HandleTopBottomCollisions(mPaddle1Pos);
	HandleTopBottomCollisions(mPaddle2Pos);

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

bool Game::BallIsAlignedWithPaddleXAxis(int mPaddlePosX)
{
	auto paddleRightSideX = mPaddlePosX + thickness / 2;
	auto paddleLeftSideX = mPaddlePosX - thickness / 2;
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

bool Game::BallTopHitPaddleBottomAlready(int paddlePositionY)
{
	auto ballTopSideY = mBallPos.y;
	auto paddleBottomSideY = paddlePositionY + mPaddleH;
	auto result = ballTopSideY <= paddleBottomSideY;

	return result;
}

bool Game::BallBottomHitPaddleTopAlready(int paddlePositionY)
{
	auto ballBottomSideY = mBallPos.y + thickness;
	auto paddleTopSideY = paddlePositionY;
	auto result = ballBottomSideY >= paddleTopSideY;

	return result;
}

bool Game::BallIsHigherThanPaddle(int paddlePositionY)
{
	auto result = mBallPos.y < paddlePositionY;
	return result;
}

bool Game::BallComesFromTop() 
{
	auto result = mBallVel.y > 0.0f;
	return result;
}

bool Game::BallBottomIsLowerThanPaddleTop(int paddlePositionY)
{
	auto result = mBallPos.y + thickness > paddlePositionY;
	return result;
}

bool Game::BallTopIsHigherThanPaddleBottom(int paddlePositionY)
{
	auto result = mBallPos.y < paddlePositionY + mPaddleH;
	return result;
}

void Game::HandleTopBottomCollisions(Game::Vector2 paddlePos)
{
	if (BallComesFromTop() &&
		BallIsHigherThanPaddle(paddlePos.y) &&
		BallBottomHitPaddleTopAlready(paddlePos.y) &&
		BallIsAlignedWithPaddleXAxis(paddlePos.x))
	{
		mBallVel.y *= -1;
	}

	if (!BallComesFromTop() &&
		!BallIsHigherThanPaddle(paddlePos.y) &&
		BallTopHitPaddleBottomAlready(paddlePos.y) &&
		BallIsAlignedWithPaddleXAxis(paddlePos.x))
	{
		mBallVel.y *= -1;
	}
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

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_Rect ball{
		mBallPos.x,
		mBallPos.y,
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	SDL_Rect paddle1{
		mPaddle1Pos.x,
		mPaddle1Pos.y,
		thickness,
		mPaddleH
	};
	SDL_RenderFillRect(mRenderer, &paddle1);

	SDL_Rect paddle2{
		mPaddle2Pos.x,
		mPaddle2Pos.y,
		thickness,
		mPaddleH
	};
	SDL_RenderFillRect(mRenderer, &paddle2);

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