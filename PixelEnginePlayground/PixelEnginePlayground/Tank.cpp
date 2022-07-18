#include "Tank.h"
#include "olcPixelGameEngine.h"

Tank::Tank(int iniXPos, int initYPos)
{
	IniXPos = iniXPos;
	InitYPos = initYPos;
}

void Draw(РЕФЕРЕНС НА геймэнджин)
{
	
	РЕФЕРЕНС НА геймэнджин.Draw(5, 5, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
}
