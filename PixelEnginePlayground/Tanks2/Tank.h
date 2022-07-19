#pragma once

#include <string>
#include "Matrix2D.h"

using namespace std;

class Tank 
{
private:
	string name;
public:
	Tank(string n);
	~Tank();
	string GetName() const { return name; }
	shared_ptr<Matrix2D> tankPicture;
};