#pragma once
#include <string>
#include "Pixel.h"

using namespace std;

class Matrix2D
{
private:
	std::string name;
public:
	Matrix2D(string n);
	~Matrix2D();
	string GetName() const { return name; }
//	int x00_00, x00_01, x00_02, x00_03, x00_04, x00_05, x00_06, x00_07, x00_08, x00_09, x00_10, x00_11, x00_12, x00_13;
	//int x00_00, x00_01, x00_02, x00_03, x00_04, x00_05, x00_06, x00_07, x00_08, x00_09, x00_10, x00_11, x00_12, x00_13;


};