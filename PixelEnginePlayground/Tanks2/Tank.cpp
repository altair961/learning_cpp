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
	//auto pixel = Pixel(0, 0, 255, 235, 205);

	PTankPicture->push_back(Pixel(0, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(1, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(2, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(3, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(4, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(5, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(6, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(7, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(8, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(9, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(10, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(11, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(12, 0, 255, 235, 205));
	PTankPicture->push_back(Pixel(13, 0, 255, 235, 205));


}
