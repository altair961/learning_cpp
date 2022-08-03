#pragma once

#include <iostream>
#include "PixelEngine.h"

int main()
{
	PixelEngine pixelEngine;
	pixelEngine.Construct(256, 240, 4, 4, false, true, false);
	pixelEngine.Start();
}