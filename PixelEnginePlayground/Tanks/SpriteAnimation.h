#pragma once
//#include "AnimationData.h"
#include <cmath>

class SpriteAnimation
{
private:
	float mInterval = 0.0f;
	int mTotalWidth = 0;
	int mTotalHeight = 0;
	int mTileCountX = 0;
	int mTileCountY = 0;
	int mTotalTileCount = 0;

	float mCurrentTime = 0.0f;
	int mCurrentTile = 0;

public:
	void SetParams(float interval, int totalWidth, int totalHeight, int tileCountX, int tileCountY, int totalTiles)
	{
		mInterval = interval;
		mTotalWidth = totalWidth;
		mTotalHeight = totalHeight;
		mTileCountX = tileCountX;
		mTileCountY = tileCountY;
		mTotalTileCount = totalTiles;
	}

	//AnimationData GetInfo(float fElapsedTime) 
	//{
	//	mCurrentTile += fElapsedTime;


	//}
};
