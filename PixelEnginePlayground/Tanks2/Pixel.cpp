#include "Pixel.h"
#include <iostream>

using namespace std;

Pixel::Pixel(
	int xPosition, 
	int yPosition, 
	int rColorChannel, 
	int gColorChannel, 
	int bColorChannel) 
	: XPosition{ xPosition }, 
		YPosition{ yPosition }, 
		RColorChannel{ rColorChannel },
		GColorChannel{ gColorChannel },
		BColorChannel{ bColorChannel }
{
}

Pixel::~Pixel()
{

	cout << "destructing pixel with x: " 
		<< XPosition << ", y: " << YPosition << "\n";
}
