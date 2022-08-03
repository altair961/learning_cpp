#include "Tank.h"
#include <iostream>

Tank::Tank()
{
	std::cout << "Tank was constructed. " << std::endl;
}

Tank::~Tank()
{
	std::cout << "Tank was destructed." << std::endl;
}

void Tank::Move() 
{
	// calculateNewPosition
	// updateMapWithNewPosition
	std::cout << "Tank moved. " << std::endl;
}