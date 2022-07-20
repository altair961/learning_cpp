#include "Tank.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

Tank::Tank(string n) : name(n)
{
	cout << "constructing " << name << endl;
}

Tank::~Tank()
{
	cout << "distructing " << name << endl;
}

void Tank::AddResource()
{
	PTankPicture.reset();
	PTankPicture = make_shared<std::vector<Pixel>>();
	auto pixel = Pixel(0, 0, 255, 235, 205);
	PTankPicture->push_back(pixel);
}
